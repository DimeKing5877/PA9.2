#include "Game.hpp"
#include "BackGroundClass.hpp"

Game::Game()
{
	initVariables();
	initWindow();
    player;
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
        while (const std::optional event = window->pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window->close();
            }
        }
        update();//calls all logic for the game
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
	// Game Logic Go Here

    //player updates
    sf::Vector2i mousePosition = sf::Mouse::getPosition();
    player.pointToMouse(mousePosition);
    player.playerMove();




    //enemys updates 







}

void Game::render()
{
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
