#ifndef KERNEL_MEM_PAGING_H
#define KERNEL_MEM_PAGING_H  

#define PAGE_PRESENT 0x01
#define PAGE_WRITABLE 0x02
#define PAGE_USER 0x04
#define PAGE_WRITETHROUGH 0x08
#define PAGE_CACHEDISABLE 0x10

#define KERNEL_VBASE 0xC0000000

extern uint32_t boot_pdir [1024];
extern uint32_t phys_allocator_ptable [1024];

void setup_paging (void);

#endif
