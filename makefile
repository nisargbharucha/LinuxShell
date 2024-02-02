# Compiler
CC = gcc
# Compiler flags
CFLAGS = -Wall

# Source files
SRC = myshell.c utility.c
# Object files
OBJ = $(SRC:.c=.o)
# Executable name
EXECUTABLE = myshell

# Targets
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXECUTABLE)
