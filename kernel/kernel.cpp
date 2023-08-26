#include "kernel.h"

 
extern "C" {

void kernel_main(void) 
{
	/* Initialize terminal interface */
	serial::SerialPort serial{};

	serial.writestring("TOMEROS BOOTED!\n");
	for (int i = 0; i < 100; i++) {
		serial.writestring("Hello, Kernel World!\n");
	}
	
	serial.writestring("AAAAAA\n");
}

} // EXTERN "C"