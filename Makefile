QEMU=qemu-system-i386

# this is bullshit & skill issue. should remove
export ASM=nasm

export ROOT_DIR=$(shell pwd)



export LEGACY_DIR=$(ROOT_DIR)/legacy_lol
export KERNEL_DIR=$(ROOT_DIR)/kernel
export BUILD_DIR=$(ROOT_DIR)/build
export ISO_DIR=$(ROOT_DIR)/build/iso

export CC_DIR=$(HOME)/opt/cross_compiler

.PHONY: kernel clean run

# this is bullshit & skill issue. should remove
simple_boot: $(LEGACY_DIR)/simple_boot.asm
	@echo Making $@
	$(ASM) -f bin $(LEGACY_DIR)/simple_boot.asm -o $(BUILD_DIR)/simple_boot.bin

# creates build/kernel.elf
kernel:
	@mkdir -p $(BUILD_DIR)
	@echo Making $@
	@$(MAKE) -C $(KERNEL_DIR) $@ --no-print-directory

# creates iso image (build/tomeros.iso)
iso_image: kernel grub.cfg
	@echo Making $@
	@mkdir -p $(ISO_DIR)/boot/grub
	@cp grub.cfg $(ISO_DIR)/boot/grub/grub.cfg
	@cp $(BUILD_DIR)/kernel.elf $(ISO_DIR)/boot/kernel.elf
	grub-mkrescue -o $(BUILD_DIR)/tomeros.iso $(ISO_DIR)

# run qemu on iso image (hopefully grub will grab my os)
run: kernel iso_image
	@echo RUNNING QEMU ON ISO IMAGE
	$(QEMU)  -serial stdio -cdrom $(BUILD_DIR)/tomeros.iso

# yes remove everything
clean:
	@echo CLEANING
	@rm -rf $(BUILD_DIR)