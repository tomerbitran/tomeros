#include "kernel.h"

 
extern "C" {

void kernel_main(void) 
{
	/* Initialize GDT */
	gdt::init_gdt();
	
	/* Initialize terminal interface */
	serial::Screen screen{};
	serial::IoPort debug_port{0x3F8};

	screen.writestring("TOMEROS BOOTED!\n");
	for (int i = 0; i < 100; i++) {
		screen.writestring("Hello, Kernel World!\n");
	}
	
	screen.writestring("AAAAAA\n");

	debug_port.writeString("Hello, Debug Port!\n");
	
}

} // EXTERN "C"