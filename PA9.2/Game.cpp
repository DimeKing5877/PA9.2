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


    //player invincability logic
    if (!player.vulnrable() && (player.getInvincalbeDuration() == 2)) {//when stat of invincability changes color of player to blue
        player.setColor(sf::Color::Blue);
        std::cout << "is Invincable" << std::endl;
    }
    if (!player.vulnrable() && (player.getInvincalbeDuration() <= 0)){//if player is invulnrable and timer is zero; reset timer and set vulnrable
        player.setVulnrabile(true);
        player.resetInvincalbeDuration();//resets duration of invicability for next time
        player.setColor(sf::Color::Green);//sets color back
    }
    if (!player.vulnrable() && (player.getInvincalbeDuration() > 0)) {//if player is invulnrable and timer is not zero; count down timer
        player.invincableCountDown(time.getDeltaTime());
    }

    //player updates
    sf::Vector2i mousePixel = sf::Mouse::getPosition(*window);//gits mouse position
    sf::Vector2f mouseWorld = window->mapPixelToCoords(mousePixel);//maps mouse position to windo condinets
    player.pointToMouse(mouseWorld);//points player to mouse
    player.playerMove(time.getDeltaTime());//registers player movment
    player.setWeaponSlot();//allows for a change in weapons for pla
    player.shootGun(mouseWorld, time.getDeltaTime());


    //enemys updates 
	//grunt.update(player.shape.getPosition(), time.getDeltaTime());
    enemySpawner.update(time.getDeltaTime());

	for (Enemy& enemy : this->enemySpawner.getAliveEnemies()) {
        enemy.update(player.shape.getPosition(), time.getDeltaTime());
    }

    //hit detection
    DamageCheck();
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

void Game::DamageCheck() {
    int enemyIndex = 0;
    for (Enemy& enemy : this->enemySpawner.getAliveEnemies()) {//loops through all enemys
        if (player.vulnrable()) {//player is vulnrable to damage
            playerIsDamaged(enemy);//chacks collision with player
        }
        if (!enemy.isDead()) {damageFromWeapon(enemy, player.getMainWeapon());}//checks all main weapon projectiles on enemy if it is not dead
        if (!enemy.isDead()) { damageFromWeapon(enemy, player.getSecondWeapon()); }//checks all second weapon projectiles on enemy if it is not dead
        if (!enemy.isDead()) { damageFromWeapon(enemy, player.getThirdWeapon()); }//checks all third weapon projectiles on enemy if it is not dead
        if (!enemy.isDead()) { damageFromWeapon(enemy, player.getFourthWeapon()); }//checks all fourth weapon projectiles on enemy if it is not dead
        if (!enemy.isDead()) { damageFromWeapon(enemy, player.getFifthWeapon()); }//checks all fifth weapon projectiles on enemy if it is not dead
        if (enemy.isDead()) {//enemy is dead, enemy.isDead()
            enemySpawner.getAliveEnemies().erase(enemySpawner.getAliveEnemies().begin() + enemyIndex);
            enemyIndex -= 1;
        }
        enemyIndex += 1;
    }
}
void Game::playerIsDamaged(Enemy& enemy){
    if (player.checkHit(enemy.shape.getGlobalBounds())) {//checks for collision with enemy and contitouse if true
        player.updateHealth(enemy.getBodyDamage());//updates player heath with enemy damage
        if (player.isDead()) {//checks if player is dead
            window->close();//if dead closes window
        }
        else {
            player.setVulnrabile(false);//if not dead gain invicability 
        }
        enemy.updateHealth(player.getBodyDamage());//updates enemy health with player damage
    }
}
void Game::damageFromWeapon(Enemy& enemy, weaponEntityClass& weapon){
    int projectileIndex = 0;
    for (Projectile& shot : weapon.getProjectile().getProjectiles()) {//loops through all projectiles of a set weapon
        if (enemy.checkHit(shot.getBounds())) {//if enemy is hit
            enemy.updateHealth(weapon.getWeaponDamage());//update enemys health
            //delete shot;
            weapon.getProjectile().getProjectiles().erase(weapon.getProjectile().getProjectiles().begin() + projectileIndex);
        }
        else {
            projectileIndex += 1;
        }
    }
}









