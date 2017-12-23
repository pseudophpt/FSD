#include <stdint.h>
#include <stddef.h>

#include "gdt.h"
#include "idt.h"
#include "mem/paging.h"
#include "mem/phys_allocator.h"

void kernel_init (void) {
    setup_gdt();
    setup_idt();
    setup_paging();
    init_phys_page_stack(); 
    while(1);
}


