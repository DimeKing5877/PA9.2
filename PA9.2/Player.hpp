#pragma once
#include "CharEntity.hpp"

class Player : public CharEntity {
public:
	Player(const double newMoveSpeed = 1.2, const int newHealth = 3, const int newNumOfSides = 1, const double newArea = 20, const sf::Color& newColor = sf::Color::White)
	: CharEntity(newMoveSpeed, newHealth, newNumOfSides, newArea, newColor) 
	{
		shape.setOrigin({float(area) , float(area)});
		shape.setPosition({(int(WINDOW_WIDTH/2)- float(area)), (int(WINDOW_LENGTH/2) - float(area))});
	}
	~Player();


	//controls

	void pointToMouse(const sf::Vector2f mousePosition);
	void playerMove();


private:
	//weapon





};








