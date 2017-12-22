bits 32

global in_byte 
global in_word
global in_long

global out_byte
global out_word
global out_long

in_byte:
    push ebp
    mov ebp, esp

    mov dx, [ebp + 8]

    inb

    leave
    ret

in_word:
    push ebp
    mov ebp, esp

    mov dx, [ebp + 8]

    inw 

    leave
    ret

in_long:
    push ebp
    mov ebp, esp

    mov dx, [ebp + 8]

    inl

    leave
    ret

out_byte:
    push ebp,
    mov ebp, esp

    mov dx, [ebp + 8]
    mov al, [ebp + 12]

    outb 

    leave 
    ret

out_word:
    push ebp,
    mov ebp, esp

    mov dx, [ebp + 8]
    mov ax, [ebp + 12]

    outw 

    leave 
    ret

out_long:
    push ebp,
    mov ebp, esp

    mov dx, [ebp + 8]
    mov eax, [ebp + 12]

    outl

    leave 
    ret

