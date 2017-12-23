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

    in al, dx

    leave
    ret

in_word:
    push ebp
    mov ebp, esp

    mov dx, [ebp + 8]

    in ax, dx

    leave
    ret

in_long:
    push ebp
    mov ebp, esp

    mov dx, [ebp + 8]

    in eax, dx

    leave
    ret

out_byte:
    push ebp,
    mov ebp, esp

    mov dx, [ebp + 8]
    mov al, [ebp + 12]

    out dx, al

    leave 
    ret

out_word:
    push ebp,
    mov ebp, esp

    mov dx, [ebp + 8]
    mov ax, [ebp + 12]

    out dx, ax

    leave 
    ret

out_long:
    push ebp,
    mov ebp, esp

    mov dx, [ebp + 8]
    mov eax, [ebp + 12]

    out dx, eax

    leave 
    ret

