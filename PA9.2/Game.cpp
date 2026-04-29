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
    this->renderTexture = new sf::RenderTexture({windowWidth+200, windowHeight+200});
    window->setFramerateLimit(60);
}


Game::~Game()
{
    delete background;
	delete renderTexture;
    delete window;
}

void Game::runGame()
{
    while (isRunning())
    {
        pollEvents();
        update();//calls all logic for the game
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
    time.nextDeltaTime();
	// Game Logic Go Here

    if (!player.vulnrable() && (player.getInvincalbeDuration() == 2)) {
        player.setColor(sf::Color::Blue);
        std::cout << "is Invincable" << std::endl;
    }
    if (!player.vulnrable() && (player.getInvincalbeDuration() <= 0)){//if player is invulnrable and timer is zero; reset timer and set vulnrable
        player.setVulnrabile(true);
        player.resetInvincalbeDuration();
        player.setColor(sf::Color::Green);
    }
    if (!player.vulnrable() && (player.getInvincalbeDuration() > 0)) {//if player is invulnrable and timer is not zero; count down timer
        player.invincableCountDown(time.getDeltaTime());
    }

    //player updates
    sf::Vector2i mousePosition = sf::Mouse::getPosition();


    sf::Vector2i mousePixel = sf::Mouse::getPosition(*window);
    sf::Vector2f mouseWorld = window->mapPixelToCoords(mousePixel);
    player.pointToMouse(mouseWorld);
    player.playerMove(time.getDeltaTime());
    player.setWeaponSlot();
    player.shootGun(mouseWorld, time.getDeltaTime());


    //enemys updates 
	//grunt.update(player.shape.getPosition(), time.getDeltaTime());
    enemySpawner.update(time.getDeltaTime());

	for (Enemy& enemy : this->enemySpawner.getAliveEnemies()) {
        enemy.update(player.shape.getPosition(), time.getDeltaTime());
    }

    //tests pewpew.update();//works

    //hit detection
    if (player.vulnrable()) {//player is vulnrable to damage
        this->playerIsDamaged();
    }
    if(!player.isDead()) {
        this->damagedAnEnemy();
    }


}

void Game::render()
{
    window->clear(sf::Color::Black);
	renderTexture->clear(sf::Color::Transparent);

    // Lazy initialize background (once window exists)
    if (!background) {
        background = new BackGround();
    }

    // Draw background scaled to window
    if (background) {
        background->draw(window);
    }


	//all draw functions go here
    player.draw(window);
	//grunt.draw(window);

    for (Enemy& enemy : this->enemySpawner.getAliveEnemies()) {
		window->draw(enemy.shape);
    }

    //extra pewpew.draw(window); //works


    // Display everything
   window->display();
}

bool Game::isRunning() const
{
    return window->isOpen();
}








