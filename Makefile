# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c11

# Target executable name
TARGET = calculate

# Source files
SRCS = ./src/main.c ./src/stack.c ./src/functions.c

# Object files (same as source files but with .o extension)
OBJS = $(SRCS:.c=.o)

# Header files
HEADERS = ./include/stack.h ./include/functions.h

# Default target: compile everything
all: $(TARGET)

# Link object files to create the final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets (targets that are not actual files)
.PHONY: all clean