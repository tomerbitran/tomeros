QEMU=qemu-system-i386

BOOT_DIR=kernel/boot
KERNEL_DIR=kernel
BUILD_DIR=build


simple_boot: $(BOOT_DIR)/simple_boot.asm
	@echo Making $@
	$(ASM) -f bin $(BOOT_DIR)/simple_boot.asm -o $(BUILD_DIR)/simple_boot.bin

kernel: 
	$(MAKE) -C $(KERNEL_DIR)

run: kernel
	@echo RUNNING
	$(QEMU) AAA AAA AAA AAA

clean:
	@echo CLEANING
	rm $(BUILD_DIR)/boot.bin