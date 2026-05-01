#pragma once
#include "Game.hpp"
#include "TestCases.hpp"


int main()
{
    //rand 
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    testCases tests;
    tests.runAllTests();

    Game* game = new Game();
    game->runGame();
    delete game;
    return 0;
}