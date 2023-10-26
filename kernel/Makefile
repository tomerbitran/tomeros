ASM = nasm
CXX = $(HOME)/opt/cross_compiler/bin/i386-elf-g++
CC 	= $(HOME)/opt/cross_compiler/bin/i386-elf-gcc

OPT_LEVEL:=-O2

# INCLUDE_PATH= $(HOME)/opt/cross_compiler/lib/gcc/i386-elf/9.3.0/include
ASM_FLAGS:= -f elf32
CPP_FLAGS:=$(CPP_FLAGS) -ffreestanding $(OPT_LEVEL) -Wall -Wextra -fno-exceptions -fno-rtti -fno-plt -fno-pic
LD_FLAGS:=$(LD_FLAGS) -T linker.ld -ffreestanding -nostdlib -lgcc

CRTI_OBJ=crti.o
CRTBEGIN_OBJ:=$(shell $(CC) $(CFLAGS) -print-file-name=crtbegin.o)
CRTEND_OBJ:=$(shell $(CC) $(CFLAGS) -print-file-name=crtend.o)
CRTN_OBJ=crtn.o


MODULES:=boot.module utils.module memory.module interrupts.module

.PHONY: kernel

export

%.module: %
	@echo BUILDING MODULE $<
	@$(MAKE) -C $< --no-print-directory

kernel: $(MODULES) kernel.elf
	@echo BUILT KERNEL

kernel.elf: $(MODULES) $(BUILD_DIR)/kernel.o $(CRTI_OBJ) $(CRTN_OBJ)
	$(eval OBJECT_LIST := $(wildcard $(BUILD_DIR)/*.o))

	$(eval _OBJECT_LIST := $(patsubst $(BUILD_DIR)/%.c, %.o, $(OBJECT_LIST)))

	@echo LINKING $(OBJECT_LIST)
	@cp linker.ld $(BUILD_DIR)/linker.ld
	@cd $(BUILD_DIR); \
	$(CC) $(LD_FLAGS) $(_OBJECT_LIST) -o $(BUILD_DIR)/$@

%.o: %.s
	@touch $(BUILD_DIR)/$@
	$(ASM) $< $(ASM_FLAGS) -o $(BUILD_DIR)/$@

$(BUILD_DIR)/%.o: %.cpp
	$(CXX) $(CPP_FLAGS) -c $< -o $@
	@echo "Compiled $< successfully!"