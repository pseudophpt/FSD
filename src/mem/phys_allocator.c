#include <stddef.h>
#include <stdint.h>

#include "phys_allocator.h"

uint32_t *phys_page_stack = (uint32_t *)PHYS_STACK_BASE;

void init_phys_page_stack (void) {
    for (int page = 0; page < (1 << 20); page ++) {
        /* If page is anywhere that's reserved for the kernel */
        if ((page & 0xFF800) == 0xC0000)
            page = 0xC0800;
        
        /* Write page to stack and decrement stack pointer */
        phys_page_stack --;
        *phys_page_stack = (page << 12); 
    }   
}

uint32_t *pop_phys_page (void) {
    uint32_t *page;
    
    /* If there are no pages left, fail */
    if ((uint32_t)phys_page_stack >= (uint32_t)PHYS_STACK_BASE) {
        while(1);
    }
    else {
        page = (uint32_t *)(*phys_page_stack);
        phys_page_stack ++;
    }

    return page;
}

void push_phys_page(uint32_t *page) {
    /* Make space for the page and push it */
    phys_page_stack --;
    *phys_page_stack = (uint32_t)page;
}
