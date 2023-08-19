ASM=nasm
CC=g++
QEMU=qemu-system-x86_64

BOOT_DIR=src/boot
KERNEL_DIR=src/kernel
BUILD_DIR=build


boot: $(BOOT_DIR)/boot.asm
	@echo Making $@
	$(ASM) -f bin $(BOOT_DIR)/boot.asm -o $(BUILD_DIR)/boot.bin

kernel:
	@echo Making $@
	touch aaa
	rm aaa

# run qemu on boot binary 
run: boot
	@echo RUNNING
	$(QEMU) $(BUILD_DIR)/boot.bin

clean:
	@echo CLEANING
	rm $(BUILD_DIR)/boot.bin