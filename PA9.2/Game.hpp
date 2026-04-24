#pragma once
#include "MainHeader.hpp"
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

	// Init Functions
	void initWindow();
	void initVariables();
};