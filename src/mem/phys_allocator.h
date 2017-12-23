#ifndef KERNEL_MEM_PHYS_ALLOCATOR_H
#define KERNEL_MEM_PHYS_ALLOCATOR_H

#define PAGE_SIZE 0x1000
#define PHYS_STACK_BASE (uint32_t *)0xC0400000;

void init_phys_page_stack (void);

#endif
