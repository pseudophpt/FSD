#include <stdint.h>
#include <stddef.h>

#include "idt.h"
#include "gdt.h"
#include "drivers/exception.h"

void encode_idtentry (uint8_t *entry_ptr, idt_entry_t *entry) {
    
    /* Encode offset */
    
    entry_ptr[0] = entry->offset & 0xFF;
    entry_ptr[1] = (entry->offset >> 8) & 0xFF;
    entry_ptr[6] = (entry->offset >> 16) & 0xFF;
    entry_ptr[7] = (entry->offset >> 24) & 0xFF;
    
    /* Encode selector */
    
    entry_ptr[2] = (entry->selector) & 0xFF;
    entry_ptr[3] = (entry->selector >> 8) & 0xFF;
    
    /* Encode type */

    entry_ptr[4] = 0;
    entry_ptr[5] = entry->type;
    
}

void setup_idt (void) {
    
    /* IDT entries for exceptions */
    
    idt_entry_t divbyzero = {.offset = (uint32_t)handle_divbyzero_entry, .selector = KERNEL_CODE_SEGMENT, .type = 0x8E};
    idt_entry_t overflow = {.offset = (uint32_t)handle_overflow_entry, .selector = KERNEL_CODE_SEGMENT, .type = 0x8E};
    idt_entry_t invalidopcode = {.offset = (uint32_t)handle_invalidopcode_entry, .selector = KERNEL_CODE_SEGMENT, .type = 0x8E};
    idt_entry_t doublefault = {.offset = (uint32_t)handle_doublefault_entry, .selector = KERNEL_CODE_SEGMENT, .type = 0x8E};
    idt_entry_t invalidtss = {.offset = (uint32_t)handle_invalidtss_entry, .selector = KERNEL_CODE_SEGMENT, .type = 0x8E};
    idt_entry_t stackfault = {.offset = (uint32_t)handle_stackfault_entry, .selector = KERNEL_CODE_SEGMENT, .type = 0x8E};
    idt_entry_t gpfault = {.offset = (uint32_t)handle_gpfault_entry, .selector = KERNEL_CODE_SEGMENT, .type = 0x8E};
    idt_entry_t pagefault = {.offset = (uint32_t)handle_pagefault_entry, .selector = KERNEL_CODE_SEGMENT, .type = 0x8E};
    idt_entry_t floaterror = {.offset = (uint32_t)handle_floaterror_entry, .selector = KERNEL_CODE_SEGMENT, .type = 0x8E};
    
    /* Encode them */
    
    encode_idtentry(&idt[0 << 3], &divbyzero);
    encode_idtentry(&idt[4 << 3], &overflow);
    encode_idtentry(&idt[6 << 3], &invalidopcode);
    encode_idtentry(&idt[8 << 3], &doublefault);
    encode_idtentry(&idt[10 << 3], &invalidtss);
    encode_idtentry(&idt[12 << 3], &stackfault);
    encode_idtentry(&idt[13 << 3], &gpfault);
    encode_idtentry(&idt[14 << 3], &pagefault);
    encode_idtentry(&idt[16 << 3], &floaterror);
    
    /* Tell x86 where IDT is */
    
    load_idt(idt, sizeof(idt));
}
