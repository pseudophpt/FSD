#ifndef KERNEL_MEM_PHYS_ALLOCATOR_H
#define KERNEL_MEM_PHYS_ALLOCATOR_H

#define PAGE_SIZE 0x1000
#define PHYS_STACK_BASE (uint32_t *)0xC0800000
#define PHYS_STACK_TOP (uint32_t *)0xC0400000

uint32_t *pop_phys_page (void); 
void push_phys_page(uint32_t *page); 
void init_phys_page_stack (void);

#endif
