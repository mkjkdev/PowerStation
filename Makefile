#/***
# * @brief Makefile for the project
# * @author mkjkdev
# * @date 18/07/2026
# * 
#*/

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude

# Directories
SRC_DIR = src
INC_DIR = include
BIN_DIR = bin

# Executable name
TARGET = $(BIN_DIR)/PowerStation

# Source files
SRCS = main.cpp \
       $(SRC_DIR)/Date.cpp \
       $(SRC_DIR)/PowerCollector.cpp \
       $(SRC_DIR)/Utilities.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Link object files
$(TARGET): $(OBJS)
	mkdir -p $(BIN_DIR)
	$(CXX) $(OBJS) -o $(TARGET)

# Compile source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Remove build files
clean:
	rm -f $(OBJS)
	rm -rf $(BIN_DIR)

# Rebuild everything
rebuild: clean all

# Run the program
run: all
	./$(TARGET)

.PHONY: all clean rebuild run