#pragma once 
#include "WeaponEntityClass.hpp"

weaponEntityClass::weaponEntityClass(const sf::Color newColor, float x_coordinate, float y_coordinate){
	this->x_coordinate = x_coordinate;
	this->y_coordinate = y_coordinate;
	this->objectColor = newColor;
}

void weaponEntityClass::setXCoordinate(float newXCoordinate)
{
	this->x_coordinate = newXCoordinate;
}

void weaponEntityClass::setYCoordinate(float newYCoordinate)
{
	this->y_coordinate = newYCoordinate;
}

void weaponEntityClass::setColor(const sf::Color newColor)
{
	this->objectColor = newColor;
}

float weaponEntityClass::getXCoordinate() const
{
	return this->x_coordinate;
}

float weaponEntityClass::getYCoordinate() const
{
	return this->y_coordinate;
}
