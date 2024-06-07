#!/bin/bash
gcc -I/mingw64/include/SDL2 -Dmain=SDL_main -o mazegame main.c -L/mingw64/lib -lmingw32 -lSDL2main -lSDL2
