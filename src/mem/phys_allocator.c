#include <stddef.h>
#include <stdint.h>

#include "phys_allocator.h"

uint32_t *phys_page_stack = (uint32_t *)0xC07FFFFC;

void init_phys_page_stack (void) {
    for (int page = 0; page < (1 << 20); page ++) {
        /* If page is anywhere that's reserved for the kernel */
        if ((page & 0xFF800) == 0xC0000)
            page = 0xC0800;
        
        /* Write page to stack and decrement stack pointer */
        *phys_page_stack = (page << 12); 
        phys_page_stack --;
    }   
}
