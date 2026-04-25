#pragma once
#include "MainHeader.hpp"
#include "Player.hpp"
#include "BackGroundCLass.hpp"


class player;
class BackGround;

class Game
{
public:
	// Constructors and Destructors
	Game();
	virtual ~Game();

	// The main loop of our game
	void runGame();

	// Other Functions
	void update();
	void render();
	bool isRunning() const;

private:
	// Attributes
	sf::RenderWindow* window;
	BackGround* background;

	Player player;//the player

	// Init Functions
	void initWindow();
	void initVariables();
};