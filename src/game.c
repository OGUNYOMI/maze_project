#include "game.h"
#include <stdio.h>
#include <stdlib.h>

Player player;
Maze maze;

void init_game(Game* game) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
        exit(1);
    }

    game->screenWidth = 640;
    game->screenHeight = 480;
    game->window = SDL_CreateWindow("Maze Game", 100, 100, game->screenWidth, game->screenHeight, SDL_WINDOW_SHOWN);
    if (!game->window) {
        fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        exit(1);
    }

    game->renderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!game->renderer) {
        SDL_DestroyWindow(game->window);
        fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_Quit();
        exit(1);
    }

    // Initialize player position and direction
    player.x = 1.5;
    player.y = 1.5;
    player.dirX = -1.0;
    player.dirY = 0.0;
    player.planeX = 0.0;
    player.planeY = 0.66;

    // Initialize the maze
    maze.width = 10;
    maze.height = 10;
    maze.map = (int**)malloc(maze.height * sizeof(int*));
    for (int i = 0; i < maze.height; i++) {
        maze.map[i] = (int*)malloc(maze.width * sizeof(int));
    }

    // Fill the maze with example data (1 = wall, 0 = empty space)
    int exampleMap[10][10] = {
        {1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,1,0,1,0,1,0,0,1},
        {1,0,1,0,1,0,1,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,1,0,1,0,1,0,0,1},
        {1,0,1,0,1,0,1,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1}
    };
    for (int y = 0; y < maze.height; y++) {
        for (int x = 0; x < maze.width; x++) {
            maze.map[y][x] = exampleMap[y][x];
        }
    }
}

void game_loop(Game* game) {
    int running = 1;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }

        const Uint8* state = SDL_GetKeyboardState(NULL);
        if (state[SDL_SCANCODE_ESCAPE]) {
            running = 0;
        }

        // Handle player movement (not required for this task but needed later)

        render_frame(game);
    }

    // Clean up
    SDL_DestroyRenderer(game->renderer);
    SDL_DestroyWindow(game->window);
    SDL_Quit();
}
