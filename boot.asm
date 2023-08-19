org 0x7c00 
bits 16

%define ENDL 0x0D, 0x0A

start:
    jmp bootloader_main

; puts - prints string to screen (using bios shit intterupt)
; Params: 
;        1. (ds:si) - pointer to the null terminated string
simple_puts:
    push si
    push ax

    mov ah, 0x0e 
._simple_puts_loop:
    mov al, byte [ds:si]
    or al, al                   ; test null char
    jz ._simple_puts_finish

    inc si                      ; increment pointer
    int 0x10                    ; print char

    jmp ._simple_puts_loop 
._simple_puts_finish:
    pop ax 
    pop si
    ret

bootloader_main: 
    ; setup ds, es
    mov ax, 0 
    mov ds, ax ; data segment start to 0 
    mov es, ax ; idk what es is wtf

    ; setup stack - will begin at 0x7c00 
    mov ss, ax ; stack segment start to 0
    mov sp, 0x7c00

    mov si, _STR_BOOTING
    call simple_puts

    

    
_STR_BOOTING: db "Booting with Tomer... ", ENDL, 0

times 510 - ($ - $$) db 0
dw 0xAA55