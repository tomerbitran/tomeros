utils: string.o serial.o
	@mv string.o $(ROOT_DIR)/$(BUILD_DIR)/string.o
	@mv serial.o $(ROOT_DIR)/$(BUILD_DIR)/serial.o

%.o: %.cpp %.h
	$(CXX) -c $< $(CPP_FLAGS) -o $@