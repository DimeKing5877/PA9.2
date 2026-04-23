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
	Game();
	virtual ~Game();

	void runGame();
	void update();
	void render();

	bool isRunning() const;

private:
	sf::Window* window;

	// Init Functions
	void initWindow();
	void initVariables();
};