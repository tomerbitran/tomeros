ASM = nasm
CXX = g++  # TODO: switch to i386 cc
CC	= gcc  # TODO: switch to i386 cc

OPT_LEVEL:=-O0

export ASM_FLAGS:= -f elf32
export CPP_FLAGS:=$(CPP_FLAGS) -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti -fno-plt -fno-pic -m32
export LD_FLAGS:=$(LD_FLAGS) -T linker.ld -ffreestanding $(OPT_LEVEL) -nostdlib -lgcc

OBJECT_LIST=kernel_main.o
OBJECT_LIST+=boot.o

_OBJECT_LIST=$(patsubst $(ROOT_DIR)/$(BUILD_DIR)/%.c, %.o, $(OBJECT_LIST))
MODULES:=boot.module

.PHONY: kernel

%.module: %
	@echo BUILDING MODULE $<
	@$(MAKE) -C $< --no-print-directory

kernel: $(MODULES) kernel.elf
	@echo BUILT KERNEL

kernel.elf: $(MODULES) kernel_main.o
	@echo AAAAA $(OBJECT_LIST)
	@cp linker.ld $(ROOT_DIR)/$(BUILD_DIR)/linker.ld
	@cd $(ROOT_DIR)/$(BUILD_DIR); \
	$(CC) $(LDFLAGS) $(_OBJECT_LIST) -o $(ROOT_DIR)/$(BUILD_DIR)/$@

%.o: %.s
	@touch $(ROOT_DIR)/$(BUILD_DIR)/$@
	$(ASM) $< $(ASM_FLAGS) -o $(ROOT_DIR)/$(BUILD_DIR)/$@

%.o: %.cpp %.h
	$(CXX) -c $< $(CPPFLAGS) -o $@
	cp $@ $(ROOT_DIR)/$(BUILD_DIR)/$@
	rm $@