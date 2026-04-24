#include "Game.hpp"
#include "BackGroundCLass.hpp"

Game::Game()
{
	initVariables();
	initWindow();
}

// Inits variables for the window.
void Game::initVariables()
{
	this->windowWidth = 1000;
    this->windowHeight = 800;
	this->windowTitle = "Tanks Alot";
	this->vm = sf::VideoMode({windowWidth, windowHeight});
    this->window = nullptr;
    this->background = nullptr;
}

// Inits the window using the variables defined in initVariables.
void Game::initWindow()
{
    this->window = new sf::RenderWindow(vm, windowTitle, sf::Style::Titlebar | sf::Style::Close);
    window->setFramerateLimit(60);
}


Game::~Game()
{
    delete background;
    delete window;
}

void Game::runGame()
{
    while (isRunning())
    {
        update();
        render();
    }
}

void Game::pollEvents()
{
    while (const std::optional event = window->pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            window->close();
        }
    }
}

void Game::update()
{
    pollEvents();
    // Game Logic Goes Here
	deltaTime.getDeltaTime();
}

void Game::render()
{
    window->clear();

	// Draw functions go here

    window->display();
}

bool Game::isRunning() const
{
    return window->isOpen();
}
