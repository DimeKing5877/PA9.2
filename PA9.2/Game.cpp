#include "Game.hpp"
#include "BackGroundCLass.hpp"

Game::Game()
{
	initVariables();
	initWindow();
}

// Put functions that are used to help initialize the window
void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode({ 1000, 800 }), "Game.io", sf::Style::Titlebar | sf::Style::Close);
    window->setFramerateLimit(60);
}

// Same thing as initWindow but for variables.
void Game::initVariables()
{
    this->window = nullptr;
    this->background = nullptr;

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
        while (const std::optional event = window->pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window->close();
            }
        }
        update();
        render();
    }
}

void Game::update()
{
	// Game Logic Go Here
}

void Game::render()
{
    // Clear the window
    window->clear(sf::Color::Black);

    // Lazy initialize background (once window exists)
    if (!background) {
        background = new BackGround();
    }

    // Draw background scaled to window
    if (background) {
        background->draw(window);
    }

    // Display everything
    window->display();
}

bool Game::isRunning() const
{
    return window->isOpen();
}
