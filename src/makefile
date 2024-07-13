# This Makefile compiles and links a C program named "todo_list" using gcc.

# Specify the compiler to use
CC = gcc

# Specify compiler flags to use for all compilations:
# -Wall: Enables all compiler's warning messages
# -Wextra: Enables additional warning messages
CFLAGS = -Wall -Wextra -g -O0 --coverage

# List of source files in the project
SRCS = test_datei.c

# Generate the list of object files from the source files
OBJS = $(SRCS:.c=.o)

# Define the final executable name
TARGET = todo_list

# Define the default target that will be built when no specific target is specified.
.PHONY: all
all: $(TARGET)

# Pattern rule for compiling C files into object files.
# $< is the automatic variable that holds the name of the prerequisite
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to link the object files into the final executable.
# $@ is the automatic variable that holds the name of the target
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@

# Clean up the build directory by removing the object files and the executable.
# This is a phony target because it does not correspond to a real file name.
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)
