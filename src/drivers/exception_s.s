bits 32

extern handle_divbyzero
extern handle_overflow
extern handle_invalidopcode
extern handle_doublefault
extern handle_invalidtss
extern handle_stackfault
extern handle_gpfault
extern handle_pagefault
extern handle_floaterror

global handle_divbyzero_entry
global handle_overflow_entry
global handle_invalidopcode_entry
global handle_doublefault_entry
global handle_invalidtss_entry
global handle_stackfault_entry
global handle_gpfault_entry
global handle_pagefault_entry
global handle_floaterror_entry

global debug_registers

handle_divbyzero_entry:
    call store_debug
    call handle_divbyzero
    iretd

handle_overflow_entry:
    call store_debug
    call handle_overflow
    iretd

handle_invalidopcode_entry:
    call store_debug
    call handle_invalidopcode
    iretd

handle_doublefault_entry:
    add esp, 4 ; pop error code
    call store_debug
    call handle_doublefault
    iretd

handle_invalidtss_entry:
    add esp, 4 ; pop error code
    call store_debug
    call handle_invalidtss
    iretd

handle_stackfault_entry:
    add esp, 4 ; pop error code
    call store_debug
    call handle_stackfault
    iretd

handle_gpfault_entry:
    add esp, 4 ; pop error code
    call store_debug
    call handle_gpfault
    iretd

handle_pagefault_entry:
    add esp, 4 ; pop error code
    call store_debug
    call handle_pagefault
    iretd

handle_floaterror_entry:
    call store_debug
    call handle_floaterror
    iretd

store_debug:
    mov [debug_registers], eax
    mov [debug_registers + 4], ebx
    mov [debug_registers + 8], ecx
    mov [debug_registers + 12], edx
    
    mov [debug_registers + 16], esi
    mov [debug_registers + 20], edi
    mov [debug_registers + 24], ebp
    
    mov eax, [esp + 16] ; esp
    mov [debug_registers + 28], eax
    
    mov eax, [esp + 4] ; eip
    mov [debug_registers + 32], eax
    
    mov eax, [esp + 8] ; cs
    mov [debug_registers + 36], eax
    
    mov eax, [esp + 20] ; ss
    mov [debug_registers + 40], eax
    
    mov eax, [esp + 12] ; eflags 
    mov [debug_registers + 44], eax
    
    ret

debug_registers: resb (12 * 4)

