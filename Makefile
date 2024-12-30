# Compiler and flags
CC = g++
CFLAGS = -Wall -g -Iinclude -O3

# Directories
INC_DIR = include
BIN_DIR = bin

# Source files and output
SRC = main.cpp
TARGET = $(BIN_DIR)/game

# Rule to build the final program
$(TARGET): $(SRC)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Clean up build files
clean:
	rm -rf $(BIN_DIR)

# Phony targets
.PHONY: clean
