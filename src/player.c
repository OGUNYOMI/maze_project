#include "game.h"
#include <math.h>

void move_player(Player* player, Maze* maze, double moveSpeed, double rotSpeed) {
    if (moveSpeed != 0) {
        if (maze->map[(int)(player->x + player->dirX * moveSpeed)][(int)(player->y)] == 0) player->x += player->dirX * moveSpeed;
        if (maze->map[(int)(player->x)][(int)(player->y + player->dirY * moveSpeed)] == 0) player->y += player->dirY * moveSpeed;
    }
    if (rotSpeed != 0) {
        double oldDirX = player->dirX;
        player->dirX = player->dirX * cos(-rotSpeed) - player->dirY * sin(-rotSpeed);
        player->dirY = oldDirX * sin(-rotSpeed) + player->dirY * cos(-rotSpeed);
        double oldPlaneX = player->planeX;
        player->planeX = player->planeX * cos(-rotSpeed) - player->planeY * sin(-rotSpeed);
        player->planeY = oldPlaneX * sin(-rotSpeed) + player->planeY * cos(-rotSpeed);
    }
}
