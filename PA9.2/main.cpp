#include "Game.hpp"


int main()
{
    Game* game = new Game();
    game->runGame();
    delete game;
    return 0;
}