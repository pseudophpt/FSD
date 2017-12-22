bits 32

global load_gdt

KERNEL_CODE equ (0x01) << 3
KERNEL_DATA equ (0x02) << 3

gdtr:
    dw 0
    dd 0

load_gdt:
    push ebp
    mov ebp, esp
    
    push ax
    
    mov ax, word [ebp + 12] 
    mov [gdtr], ax
 
    mov eax, dword [ebp + 8]  
    mov [gdtr + 2], eax
    
    lgdt [gdtr]
    
    jmp KERNEL_CODE:.jmp ; far jump loads new code segment
    
.jmp:
    mov ax, KERNEL_DATA
    
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    mov ss, ax
    
    pop ax
    
    leave
    ret
