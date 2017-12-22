#ifndef KERNEL_IDT_H
#define KERNEL_IDT_H

typedef struct idt_entry {
    uint32_t offset;
    uint16_t selector;
    uint8_t type;
} idt_entry_t;

uint8_t idt [256 * 8];

extern void load_idt(uint8_t idt[], uint32_t idt_size);

void encode_idtentry (uint8_t *entry_ptr, idt_entry_t *entry); 
void setup_idt(void);

#endif
