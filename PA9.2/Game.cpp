#include "Game.hpp"

Game::Game()
{
	initVariables();
	initWindow();
    player;
}

// Put functions that are used to help initialize the window
void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode({ WINDOW_WIDTH, WINDOW_LENGTH }), "Game.io", sf::Style::Titlebar | sf::Style::Close);
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
        update();//calls all logic for the game
        render();
    }
}

void Game::update()
{
	// Game Logic Go Here

    //player updates
    sf::Vector2i mousePosition = sf::Mouse::getPosition();
    player.pointToMouse(mousePosition);
    player.playerMove();




    //enemys updates 







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
    player.draw(window);
    // Display everything
   window->display();
}

bool Game::isRunning() const
{
    return window->isOpen();
}
