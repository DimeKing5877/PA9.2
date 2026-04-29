#pragma once

#include "Enemy.hpp"

// Names are placeholders and can be changed if we want to.
// All colors for each enemy are placeholders
// All enemy shapes are currently traingles and therefore place holders
// Examples of different melee enemies

// The light version of the melee enemy, fast but low health.
class Drone : public Enemy
{
public:
	Drone(const double newMoveSpeed = 1.5, const int newHealth = 1, const int newNumOfSides = 3, const double newArea = 10, const sf::Color& newColor = sf::Color::Yellow)
		: Enemy(newMoveSpeed, newHealth, newNumOfSides, newArea, newColor) {}
};

// The kinda fast version of the melee enemy, a little faster than the grunt but less healt.
class Jackal : public Enemy
{
public:
	Jackal(const double newMoveSpeed = 1.25, const int newHealth = 2, const int newNumOfSides = 3, const double newArea = 15, const sf::Color& newColor = sf::Color::Blue)
		: Enemy(newMoveSpeed, newHealth, newNumOfSides, newArea, newColor) {}
};

// The basic melee enemy, generic melee unit.
class Grunt : public Enemy
{
public:
	Grunt(const double newMoveSpeed = 1.0, const int newHealth = 3, const int newNumOfSides = 4, const double newArea = 20, const sf::Color& newColor = sf::Color::Red)
		: Enemy(newMoveSpeed, newHealth, newNumOfSides, newArea, newColor) {}
};


// The fast heavy melee enemy, pretty fast but can take a lot of damage, the second most dangerous enemy
class Elite : public Enemy
{
public:
	Elite(const double newMoveSpeed = 1.1, const int newHealth = 5, const int newNumOfSides = 5, const double newArea = 30, const sf::Color& newColor = sf::Color::Yellow)
		: Enemy(newMoveSpeed, newHealth, newNumOfSides, newArea, newColor) {}
};

// The heavy melee enemy, a little slow but high health.
class Brute : public Enemy
{
public:
	Brute(const double newMoveSpeed = 0.75, const int newHealth = 5, const int newNumOfSides = 5, const double newArea = 40, const sf::Color& newColor = sf::Color::Magenta)
		: Enemy(newMoveSpeed, newHealth, newNumOfSides, newArea, newColor) {}
};

// The tank melee enemy, very slow but can take a lot of damage, the most dangerous enemy
class Hunter : public Enemy
{
public:
	Hunter(const double newMoveSpeed = 0.5, const int newHealth = 7, const int newNumOfSides = 6, const double newArea = 50, const sf::Color& newColor = sf::Color::Cyan)
		: Enemy(newMoveSpeed, newHealth, newNumOfSides, newArea, newColor) {}
};