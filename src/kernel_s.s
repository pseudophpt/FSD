bits 32			;nasm directive - 32 bit

global loader
global boot_ptable
global boot_pdir
extern kernel_init

meminfo     equ  1<<1             ; provide memory map
modulealign equ  1<<0             ; align loaded modules on page boundaries
flags       equ  modulealign | meminfo  ; this is the Multiboot 'flag' field
magic       equ    0x1BADB002     ; 'magic number' lets bootloader find the header
checksum    equ -(magic + flags)

kernel_vbase equ 0xC0000000
kernel_pnumber equ (kernel_vbase >> 22)

section .multiboot

align 4
	dd magic              ; magic
	dd flags              ; flags
	dd - (magic + flags)  ; checksum

section .text

loader:
	mov esi, 0 ; offset from _boot_pt
	mov edi, 0 ; page to identity map
.loop:
	mov ecx, edi
	add ecx, 3 ; Permissions
	mov dword [esi + boot_ptable - kernel_vbase], ecx
	add esi, 4
	add edi, 0x1000
	cmp esi, 0x1000
	jne .loop
	; Now, the first 4MB of the kernel is identity mapped. However, we have to put this page table at virtual addresses 0x00000000 and 0xc0000000, so that when we enable paging, it can continue execution.

	mov dword [boot_pdir - kernel_vbase], boot_ptable + 0x00000003 - kernel_vbase
	mov dword [boot_pdir + (768 * 4) - kernel_vbase], boot_ptable + 0x00000003 - kernel_vbase

	mov ecx, boot_pdir - kernel_vbase
	mov cr3, ecx

	mov ecx, cr0
	or ecx, 0x80010000 ; Enable paging w/ write-protection
	mov cr0, ecx

	lea ecx, [_init_kernel]
	jmp ecx

_init_kernel:
	mov dword [boot_pdir], 0
	invlpg [0]
	mov esp, (stack_space)
	push eax
	push ebp
	call kernel_init
	cli
	hlt

section .bss

align 0x1000

boot_pdir: resb 4096
boot_ptable: resb 4096

resb 8192		;8KB for stack
stack_space:
