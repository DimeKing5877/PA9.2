#pragma once

#include "CharEntity.hpp"
#include <cmath>

// All enemies will inherit from this class
// Contains an virtualupdate function that allows for the shape to chase after player. This allows us to change the AI for ones with weapons
// Uses delta time to make sure the movement is consistent across different machines
// Will techinally be incomplete until weapon is implemented
class Enemy : public CharEntity
{
public:
	Enemy(const double newMoveSpeed, const int newHealth, const int newNumOfSides, const double newArea, const sf::Color& newColor) : CharEntity(newMoveSpeed, newHealth, newNumOfSides, newArea, newColor)
	{
		shape.setOrigin({ float(area), float(area) });
		shape.setPosition({ (int(WINDOW_WIDTH / 2) - float(area)), (int(WINDOW_LENGTH / 2) - float(area)) });
	}
	virtual ~Enemy();

	virtual void update(const sf::Vector2f playerPosition, float deltatime);

protected:
	// Weapon once the class has been implemented
};

