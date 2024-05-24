#include "game.h"
#include <math.h>

void render_frame(Game* game)
{
    SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255); // Black color for clearing screen
    SDL_RenderClear(game->renderer);

    for (int x = 0; x < game->screenWidth; x++) {
        double cameraX = 2 * x / (double)game->screenWidth - 1;
        double rayDirX = player.dirX + player.planeX * cameraX;
        double rayDirY = player.dirY + player.planeY * cameraX;

        int mapX = (int)player.x;
        int mapY = (int)player.y;

        double sideDistX;
        double sideDistY;

        double deltaDistX = (rayDirY == 0) ? 0 : ((rayDirX == 0) ? 1 : fabs(1 / rayDirX));
        double deltaDistY = (rayDirX == 0) ? 0 : ((rayDirY == 0) ? 1 : fabs(1 / rayDirY));
        double perpWallDist;

        int stepX;
        int stepY;

        int hit = 0;
        int side;

        if (rayDirX < 0) {
            stepX = -1;
            sideDistX = (player.x - mapX) * deltaDistX;
        } else {
            stepX = 1;
            sideDistX = (mapX + 1.0 - player.x) * deltaDistX;
        }
        if (rayDirY < 0) {
            stepY = -1;
            sideDistY = (player.y - mapY) * deltaDistY;
        } else {
            stepY = 1;
            sideDistY = (mapY + 1.0 - player.y) * deltaDistY;
        }

        while (hit == 0) {
            if (sideDistX < sideDistY) {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            } else {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            if (maze.map[mapY][mapX] > 0) hit = 1;
        }

        if (side == 0) perpWallDist = (mapX - player.x + (1 - stepX) / 2) / rayDirX;
        else          perpWallDist = (mapY - player.y + (1 - stepY) / 2) / rayDirY;

        int lineHeight = (int)(game->screenHeight / perpWallDist);

        int drawStart = -lineHeight / 2 + game->screenHeight / 2;
        if (drawStart < 0) drawStart = 0;
        int drawEnd = lineHeight / 2 + game->screenHeight / 2;
        if (drawEnd >= game->screenHeight) drawEnd = game->screenHeight - 1;

        int color = 0xFF0000; // Red for walls
        if (side == 1) color = color / 2; // Make side walls darker

        SDL_SetRenderDrawColor(game->renderer, (color & 0xFF0000) >> 16, (color & 0x00FF00) >> 8, color & 0x0000FF, 255);
        SDL_RenderDrawLine(game->renderer, x, drawStart, x, drawEnd);
    }

    SDL_RenderPresent(game->renderer);
}
