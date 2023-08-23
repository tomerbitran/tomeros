
boot: boot.o ;

%.o: %.s
	@touch $(ROOT_DIR)/$(BUILD_DIR)/$@
	$(ASM) $< $(ASM_FLAGS) -o $(ROOT_DIR)/$(BUILD_DIR)/$@