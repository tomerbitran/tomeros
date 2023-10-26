# Define the source files and object files
SRCS := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Define the targets
memory: $(OBJS)

$(BUILD_DIR)/%.o: %.cpp
	$(CXX) $(CPP_FLAGS) -c $< -o $@
	@echo "Compiled $< successfully!"