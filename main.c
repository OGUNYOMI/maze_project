#include "game.h"

int main() 
{
    Game game;
    init_game(&game);
    game_loop(&game);
    return 0;
}
