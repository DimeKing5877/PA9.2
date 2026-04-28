#include "Game.hpp"


int main()
{
    //rand 
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    Game* game = new Game();
    game->runGame();
    delete game;
    return 0;
}