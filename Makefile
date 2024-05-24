CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
SDL2_CFLAGS = $(shell sdl2-config --cflags)
SDL2_LDFLAGS = $(shell sdl2-config --libs)

SRC = src/main.c src/game.c src/raycasting.c src/player.c src/utils.c
OBJ = $(SRC:.c=.o)
DEPS = inc/game.h

all: maze_game

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) $(SDL2_CFLAGS) -c -o $@ $<

maze_game: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(SDL2_LDFLAGS)

clean:
	rm -f $(OBJ) maze_game

.PHONY: clean
