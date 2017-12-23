#include <stdint.h>
#include <stddef.h>

#include "paging.h"

void setup_paging (void) {
    /* Add entry to identity map 0xC0400000 to its physical equivalent */
    boot_pdir[769] = ((uint32_t)phys_allocator_ptable - KERNEL_VBASE) | PAGE_PRESENT | PAGE_WRITABLE;

    for (int i = 0; i < 1024; i ++) {
        phys_allocator_ptable[i] = (0x400000 + (i << 12)) | PAGE_PRESENT | PAGE_WRITABLE;
    }
}


void map_page (void) {
    
}
