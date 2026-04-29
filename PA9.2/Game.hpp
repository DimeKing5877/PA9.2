#pragma once
#include <iostream>

#include <SFML/Graphics.hpp>

#include "Time.hpp"
#include "MainHeader.hpp"
#include "Player.hpp"
#include "BackGroundCLass.hpp"
#include "WeaponEntityClass.hpp"
#include "BasicEnemies.hpp"
#include "Spawner.hpp"


class player;
class BackGround;

class Game
{
public:
	// Constructors and Destructors
	Game();
	~Game();

	// The main loop of our game
	void runGame();

private:
	unsigned int windowWidth;
	unsigned int windowHeight;
	std::string windowTitle;
	sf::VideoMode vm;
	sf::RenderWindow* window;
	sf::RenderTexture* renderTexture;
	Time time;
	BackGround* background;



	Player player;//the player
	Grunt grunt;//generic enemy

	
	void generateEnemy();//generates an enemy 

	//extra
	WeaponClass pewpew;


	//need an array/list of all enemys
	Spawner enemySpawner;



	// Init Functions
	void initWindow();
	void initVariables();

	// Other Functions
	void pollEvents();
	void update();
	void render();
	bool isRunning() const;



	//hit Detection
	void playerIsDamaged();
	void damagedAnEnemy();

};