bits 32

global load_idt

idtr:
    dw 0
    dd 0

load_idt:
    push ebp
    mov ebp, esp
    
    push ax
    
    mov ax, word [ebp + 12] 
    mov [idtr], ax
 
    mov eax, dword [ebp + 8]  
    mov [idtr + 2], eax
    
    lidt [idtr]
    
    pop ax
    
    leave
    ret
