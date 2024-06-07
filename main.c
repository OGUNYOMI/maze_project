#include <SDL2/SDL.h>
#include <stdio.h>

// Function prototypes (if you have more functions, add them here)
void runGameLoop(SDL_Window *window, SDL_Renderer *renderer);

int SDL_main(int argc, char *argv[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create window
    SDL_Window *window = SDL_CreateWindow("Maze Game",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          640, 480,
                                          SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Create renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Run the game loop
    runGameLoop(window, renderer);

    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

void runGameLoop(SDL_Window *window, SDL_Renderer *renderer) {
    int running = 1;
    SDL_Event e;

    // Game loop
    while (running) {
        // Handle events
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                running = 0;
            }
        }

        // Clear screen
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF); // White
        SDL_RenderClear(renderer);

        // Draw something (e.g., a simple maze)
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF); // Black
        SDL_RenderDrawLine(renderer, 100, 100, 200, 200); // Example line

        // Update screen
        SDL_RenderPresent(renderer);
    }
}
