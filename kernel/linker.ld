/* what the fuck...linker script wizards...*/
KERNEL_VMA_START=0xf8000000;
ENTRY(_start)
SECTIONS
{
    . = KERNEL_VMA_START;

    .text : AT(ADDR(.text) - KERNEL_VMA_START)
    {
        _code = .;
        *(.text)
        *(.rodata*)
        . = ALIGN(4096);
    }

   .data : AT(ADDR(.data) - KERNEL_VMA_START)
   {
        _data = .;
        *(.data)
        . = ALIGN(4096);
   }

   .eh_frame : AT(ADDR(.eh_frame) - KERNEL_VMA_START)
   {
       _ehframe = .;
       *(.eh_frame)
        . = ALIGN(4096);
   }

   .bss : AT(ADDR(.bss) - KERNEL_VMA_START)
   {
       _bss = .;
       *(.bss)

        *(COMMON)
       . = ALIGN(4096);
   }

   _end = .;
}