#pragma once
#include <SFML/Graphics.hpp>

class Time
{
public:
	Time();
	~Time();

	void nextDeltaTime();
	float getDeltaTime() const;
private:
	sf::Clock clock;
	float deltaTime;
};