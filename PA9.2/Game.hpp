#pragma once
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

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

	// Init Functions
	void initWindow();
	void initVariables();
};