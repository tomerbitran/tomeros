; constants for the multiboot header. 
MBALIGN  equ  1 << 0                ; align loaded modules on page boundaries
MEMINFO  equ  1 << 1                ; provide memory map
MBFLAGS  equ  MBALIGN | MEMINFO     ; this is the Multiboot 'flag' field
MAGIC    equ  0x1BADB002            ; 'magic number' lets bootloader find the header
CHECKSUM equ -(MAGIC + MBFLAGS)     ; checksum of above, to prove we are multiboot

 
;Declare a multiboot header that marks the program as a kernel. 

section .multiboot
align 4
    dd MAGIC
    dd MBFLAGS
    dd CHECKSUM


; The multiboot standard does not define the value of the stack pointer register
; and it is up to the kernel to provide a stack.

section .bss
align 16

stack_bottom:
resb 16384 ; 16 KiB
stack_top:

; The linker script specifies _start as the entry point to the kernel and the
; bootloader (GRUB) will jump to this position once the kernel has been loaded.

section .text

global _start:function (_start.end - _start)
_start:

	; The bootloader (GRUB) has loaded us into 32-bit protected mode on a x86
	; machine. Interrupts are disabled, Paging is disabled. The processor
	; state is as defined in the multiboot standard.
	

    ; set up a stack
	mov esp, stack_top


	; This is a good place to initialize crucial processor state before the
	; high-level kernel is entered. It's best to minimize the early
	; environment where crucial features are offline. Note that the
	; processor is not fully initialized yet: Features such as floating
	; point instructions and instruction set extensions are not initialized
	; yet. The GDT should be loaded here. Paging should be enabled here.
	; C++ features such as global constructors and exceptions will require
	; runtime support to work as well.
	
	
    ; linker symbol 
    extern kernel_main
	call kernel_main

	cli
.WE_FUCKED_UP:	
    hlt
	jmp .WE_FUCKED_UP


; Set the size of the _start symbol to the current location '.' minus its start.
.end: