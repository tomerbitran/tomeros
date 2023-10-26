
boot: boot.o ;

%.o: %.s
	@touch $(BUILD_DIR)/$@
	$(ASM) $< $(ASM_FLAGS) -o $(BUILD_DIR)/$@