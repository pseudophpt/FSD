#ifndef KERNEL_DRIVER_EXCEPTION
#define KERNEL_DRIVER_EXCEPTION

typedef struct debug_reg {
    uint32_t eax;
    uint32_t ebx;
    uint32_t ecx;
    uint32_t edx;
    uint32_t esi;
    uint32_t edi;
    uint32_t ebp;
    uint32_t esp;
    uint32_t eip;
    uint32_t cs;
    uint32_t ss;
    uint32_t efl;
} debug_reg_t;

void handle_divbyzero (void);
void handle_overflow (void);
void handle_invalidopcode (void);
void handle_doublefault (void);
void handle_invalidtss (void);
void handle_stackfault (void);
void handle_gpfault (void);
void handle_pagefault (void);
void handle_floaterror (void);

extern void handle_divbyzero_entry (void);
extern void handle_overflow_entry (void);
extern void handle_invalidopcode_entry (void);
extern void handle_doublefault_entry (void);
extern void handle_invalidtss_entry (void);
extern void handle_stackfault_entry (void);
extern void handle_gpfault_entry (void);
extern void handle_pagefault_entry (void);
extern void handle_floaterror_entry (void);

extern debug_reg_t debug_registers;

#endif
