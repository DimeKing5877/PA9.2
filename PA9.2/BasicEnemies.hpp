#pragma once

#include "Enemy.hpp"

// Names are placeholders and can be changed if we want to.
// All colors for each enemy are placeholders
// All enemy shapes are currently traingles and therefore place holders
// Examples of different melee enemies

// The light version of the melee enemy, fast but low health;
class Pest : public Enemy
{
public:
	Pest(const double newMoveSpeed = 1.5, const int newHealth = 1, const int newNumOfSides = 1, const double newArea = 20, const sf::Color& newColor = sf::Color::Yellow)
		: Enemy(newMoveSpeed, newHealth, newNumOfSides, newArea, newColor) {}
};

// The basic melee enemy, generic melee unit.
class Grunt : public Enemy
{
public:
	Grunt(const double newMoveSpeed = 1.0, const int newHealth = 3, const int newNumOfSides = 2, const double newArea = 25, const sf::Color& newColor = sf::Color::Red)
		: Enemy(newMoveSpeed, newHealth, newNumOfSides, newArea, newColor) {}
};

// The heavy melee enemy, slow but high health.
class Brute : public Enemy
{
public:
	Brute(const double newMoveSpeed = 0.75, const int newHealth = 5, const int newNumOfSides = 4, const double newArea = 20, const sf::Color& newColor = sf::Color::Magenta)
		: Enemy(newMoveSpeed, newHealth, newNumOfSides, newArea, newColor) {}
};