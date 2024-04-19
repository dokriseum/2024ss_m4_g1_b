# Compiler
CC = gcc

# Compiler Flags
CFLAGS = -Wall -Wextra

# Source files
SRCS = test_datei.c

# Object files
OBJS = $(SRCS:.c=.o)

# Executable name
TARGET = todo_list

# Default target
.PHONY: all
all: $(TARGET)

# Compile C files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files into executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Clean up object files and executable
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)
