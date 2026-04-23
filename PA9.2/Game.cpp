#include "Game.hpp"

Game::Game()
{
	initVariables();
	initWindow();
}

void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode({ 1000, 800 }), "Game.io", sf::Style::Titlebar | sf::Style::Close);
    window->setFramerateLimit(60);
}

void Game::initVariables()
{
    this->window = nullptr;

}

Game::~Game()
{
    delete window;
}

void Game::runGame()
{
    while (isRunning())
    {
        while (const std::optional event = window->pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window->close();
            }
            update();
            render();
        }
    }
}

void Game::update()
{
	// Game Logic Go Here
}

void Game::render()
{
    // Fill in with probably the color of the background we want.
}

bool Game::isRunning() const
{
    return window->isOpen();
}
