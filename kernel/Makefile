ASM = nasm
CXX = g++  # TODO: switch to i386 cc
CC	= gcc  # TODO: switch to i386 cc

OPT_LEVEL:=-O0

export ASM_FLAGS:= -f elf32
export CPP_FLAGS:=$(CPP_FLAGS) -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti -fno-plt -fno-pic -m32
export LD_FLAGS:=$(LD_FLAGS) -T linker.ld -ffreestanding $(OPT_LEVEL) -nostdlib -lgcc

export OBJECT_LIST:=kernel_main.o
MODULES:=boot.module

.PHONY: kernel

%.module: %
	@echo BUILD MODULE $<
	@$(MAKE) -C $<

kernel: $(MODULES)
	@$(MAKE) kernel.elf
	@echo BUILT KERNEL

kernel.elf: $(MODULES)
	$(CC) $(LDFLAGS) $(OBJECT_LIST) -o 	$(ROOT_DIR)/$(BUILD_DIR)/$@

%.o: %.s
	$(ASM) $< $(ASM_FLAGS) -o $@

%.o: %.cpp %.h
	$(CXX) -c $< $(CPPFLAGS)  -o $@