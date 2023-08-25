ASM = nasm
CXX = $(HOME)/opt/cross_compiler/bin/i386-elf-g++
CC 	= $(HOME)/opt/cross_compiler/bin/i386-elf-gcc

OPT_LEVEL:=-O2

# INCLUDE_PATH= $(HOME)/opt/cross_compiler/lib/gcc/i386-elf/9.3.0/include
export ASM_FLAGS:= -f elf32
export CPP_FLAGS:=$(CPP_FLAGS) -ffreestanding $(OPT_LEVEL) -Wall -Wextra -fno-exceptions -fno-rtti -fno-plt -fno-pic
export LD_FLAGS:=$(LD_FLAGS) -T linker.ld -ffreestanding -nostdlib -lgcc

OBJECT_LIST=boot.o kernel_main.o

_OBJECT_LIST=$(patsubst $(ROOT_DIR)/$(BUILD_DIR)/%.c, %.o, $(OBJECT_LIST))
MODULES:=boot.module

.PHONY: kernel

%.module: %
	@echo BUILDING MODULE $<
	@$(MAKE) -C $< --no-print-directory

kernel: $(MODULES) kernel.elf
	@echo BUILT KERNEL

kernel.elf: $(MODULES) kernel_main.o
	@echo LINKING $(OBJECT_LIST)
	@cp linker.ld $(ROOT_DIR)/$(BUILD_DIR)/linker.ld
	@mv kernel_main.o $(ROOT_DIR)/$(BUILD_DIR)/kernel_main.o
	@cd $(ROOT_DIR)/$(BUILD_DIR); \
	$(CC) $(LD_FLAGS) $(_OBJECT_LIST) -o $(ROOT_DIR)/$(BUILD_DIR)/$@

%.o: %.s
	@touch $(ROOT_DIR)/$(BUILD_DIR)/$@
	$(ASM) $< $(ASM_FLAGS) -o $(ROOT_DIR)/$(BUILD_DIR)/$@

%.o: %.cpp %.h
	$(CXX) -c $< $(CPPFLAGS) -o $@