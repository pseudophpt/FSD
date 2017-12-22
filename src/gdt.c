#include <stddef.h>
#include <stdint.h>

#include "gdt.h"

void encode_gdtentry (uint8_t *entry_ptr, gdt_entry_t *entry) {
    
    /* Encode limit */
    
    entry_ptr[0] = entry->limit & 0xFF;
    entry_ptr[1] = (entry->limit >> 8) & 0xFF;
    entry_ptr[6] = (entry->limit >> 16) & 0xF;
    
    /* Set granular bit */
    
    entry_ptr[6] |= 0xF0;
    
    /* Encode base */
    
    entry_ptr[2] = entry->base & 0xFF;
    entry_ptr[3] = (entry->base >> 8) & 0xFF;
    entry_ptr[4] = (entry->base >> 16) & 0xFF;
    entry_ptr[7] = (entry->base >> 24) & 0xFF;
    
    /* Encode type */
    
    entry_ptr[5] = entry->type;
    
}

void setup_gdt () {
    
    gdt_entry_t null_entry = {.base = 0, .limit = 0, .type = 0};
    
    gdt_entry_t kernel_code = {.base = 0, .limit = 0xFFFFF, .type = 0x9A};
    gdt_entry_t kernel_data = {.base = 0, .limit = 0xFFFFF, .type = 0x92};
    
    gdt_entry_t user_code = {.base = 0, .limit = 0xFFFFF, .type = 0xFA};
    gdt_entry_t user_data = {.base = 0, .limit = 0xFFFFF, .type = 0xF2};
    
    gdt_entry_t tss_entry = {.base = (uint32_t)&tss, .limit = sizeof(tss), .type=0x89};

    encode_gdtentry(&gdt[0], &null_entry);
    encode_gdtentry(&gdt[8], &kernel_code);
    encode_gdtentry(&gdt[16], &kernel_data);
    encode_gdtentry(&gdt[24], &user_code);
    encode_gdtentry(&gdt[32], &user_data);
    encode_gdtentry(&gdt[40], &tss_entry);
  
    load_gdt(gdt, sizeof(gdt));
}
