#pragma once
#include <iostream>

#include <SFML/Graphics.hpp>

#include "Time.hpp"

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
	Time deltaTime;

	// Init Functions
	void initWindow();
	void initVariables();

	// Other Functions
	void pollEvents();
	void update();
	void render();
	bool isRunning() const;
};