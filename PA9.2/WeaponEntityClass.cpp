#pragma once 
#include "WeaponEntityClass.hpp"

void weaponEntityClass::setXCoordinate(float newXCoordinate)
{
	this->x_coordinate = newXCoordinate;
}

void weaponEntityClass::setYCoordinate(float newYCoordinate)
{
	this->y_coordinate = newYCoordinate;
}

float weaponEntityClass::getXCoordinate() const
{
	return this->x_coordinate;
}

float weaponEntityClass::getYCoordinate() const
{
	return this->y_coordinate;
}

void cannonWeapon::draw(sf::RenderWindow*& window){
	window->draw(this->cannonShape);
}
