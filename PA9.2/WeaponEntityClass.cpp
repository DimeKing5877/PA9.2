#pragma once 
#include "WeaponEntityClass.hpp"

weaponEntityClass::weaponEntityClass(const sf::Color newColor, float x_coordinate, float y_coordinate){
	this->x_coordinate = x_coordinate;
	this->y_coordinate = y_coordinate;
	this->objectColor = newColor;
}

void weaponEntityClass::setColor(const sf::Color newColor)
{
	this->objectColor = newColor;
}

void weaponEntityClass::setObjectPosition(float newX, float newY)
{
	this->weapon.setPosition({ newX, newY });
}

void weaponEntityClass::moveObject(float newX, float newY){
	this->weapon.move({ newX, newY });
}

sf::ConvexShape& weaponEntityClass::getShape()
{
	return this->weapon;
}

void weaponEntityClass::draw(sf::RenderWindow*& window){
	window->draw(this->weapon);
}

void weaponEntityClass::shoot(sf::Vector2f Mouse, float deltaTime, int shape, int size, float velocity)
{
	this->projectile.shoot(this->weapon.getPosition(), Mouse, velocity, deltaTime, shape, size);
}

void weaponEntityClass::update()
{
	if (!this->projectile.getProjectiles().empty()) {
		this->projectile.update();
	}
}

