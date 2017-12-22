#include <stdint.h>
#include <stddef.h>

#include "gdt.h"
#include "idt.h"

void kernel_init (void) {
    setup_gdt();
    setup_idt();
    *(int *)3 = 4;
    while(1);


}


