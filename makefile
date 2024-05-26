# Define the compiler
CC = gcc

# Define the compiler flags
CFLAGS = -Wall -Werror -g

# Define the target executable
TARGET = my_game

# Define the source files
SRCS = main.c init_game.c game_loop.c  # Add all your C source files here

# Define the object files
OBJS = $(SRCS:.c=.o)

# Build the target
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) -lSDL2

# Compile the source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up the build files
clean:
	rm -f $(TARGET) $(OBJS)
