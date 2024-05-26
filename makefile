CC = gcc
CFLAGS = -I/usr/include/SDL2
LDFLAGS = -lSDL2

all: my_game

my_game: main.o
	$(CC) -o my_game main.o $(LDFLAGS)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f my_game main.o
