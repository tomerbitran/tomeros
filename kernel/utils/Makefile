utils: string.o screen.o io_port.o 
	@mv string.o $(ROOT_DIR)/$(BUILD_DIR)/string.o
	@mv screen.o $(ROOT_DIR)/$(BUILD_DIR)/screen.o
	@mv io_port.o $(ROOT_DIR)/$(BUILD_DIR)/io_port.o

%.o: %.cpp %.h
	$(CXX) -c $< $(CPP_FLAGS) -o $@