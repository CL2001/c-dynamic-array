
CC = gcc

# Flags
CFLAGS = -Wall -Wextra -std=c11 -Iinclude

# Directories
SRC_DIR = src
BUILD_DIR = build

# Files
SRCS = $(SRC_DIR)/vector.c main.c
OBJS = $(SRCS:.c=.o)

# Output binary
TARGET = $(BUILD_DIR)/main

# Default target
all: $(BUILD_DIR) $(TARGET)

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Build target
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

# Clean build files
clean:
	rm -rf $(BUILD_DIR)

# Phony targets
.PHONY: all clean