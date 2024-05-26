#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

typedef struct {
    double x, y;       // Player position
    double dirX, dirY; // Player direction
    double planeX, planeY; // Camera plane
} Player;

typedef struct {
    int width, height;
    int** map; // 2D array representing the maze
} Maze;

typedef struct {
    SDL_Window* window;
    SDL_Renderer* renderer;
    int screenWidth;
    int screenHeight;
} Game;

void init_game(Game* game);
void game_loop(Game* game);
void render_frame(Game* game);
void move_player(Player* player, Maze* maze, double moveSpeed, double rotSpeed);

#endif
