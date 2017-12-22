#ifndef KERNEL_GDT_H
#define KERNEL_GDT_H

typedef struct gdt_entry {
    uint32_t base;  /* Base address */
    uint32_t limit; /* Limit */
    uint8_t type;   /* Type parameters */  
} gdt_entry_t;

uint8_t gdt [8 * 8];
uint8_t tss [104];

extern void load_gdt(uint8_t gdt[], uint32_t gdt_size);

void encode_gdtentry (uint8_t *entry_ptr, gdt_entry_t *entry); 
void setup_gdt ();

/* Definitions */

#define KERNEL_CODE_SEGMENT 0x08 
#define KERNEL_DATA_SEGMENT 0x10
#define USER_CODE_SEGMENT 0x18
#define USER_DATA_SEGMENT 0x20

#endif
