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
.loop:
    mov al, byte [si]
    or al, al                   ; test null char
    jz .finish

    inc si                      ; increment pointer
    int 0x10                    ; print char

    jmp .loop 
.finish:
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
    
    mov si, _STR_HALT
    call simple_puts
    
    hlt

    
_STR_BOOTING: db "Booting Tomer :D", ENDL, 0
_STR_HALT: db  "HALTING...", ENDL, 0

times 510 - ($ - $$) db 0
dw 0xAA55