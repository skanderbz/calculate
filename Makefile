CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = calculate
SRCS = ./src/main.c ./src/stack.c ./src/functions.c
OBJS = $(SRCS:./src/%.c=./bin/%.o)

# Header files
HEADERS = ./include/stack.h ./include/functions.h

# Default target: compile everything
all: $(TARGET)

# Link object files to create the final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files, stored in ./bin
./bin/%.o: ./src/%.c $(HEADERS)
	mkdir -p ./bin
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets (targets that are not actual files)
.PHONY: all clean
