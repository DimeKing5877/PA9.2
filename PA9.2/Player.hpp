#pragma once
#include "CharEntity.hpp"

class Player : public CharEntity {
public:
	Player(const double newMoveSpeed = 1.2, const int newHealth = 3, const int newNumOfSides = 3, const double newArea = 20, const sf::Color& newColor = sf::Color::White)
	: CharEntity(newMoveSpeed, newHealth, newNumOfSides, newArea, newColor) 
	{
		shape.setOrigin({float(area) , float(area)});
		shape.setPosition({(int(WINDOW_WIDTH/2)- float(area)), (int(WINDOW_LENGTH/2) - float(area))});
		isVulnrable = true;


		//cannonWeapon maingun(newArea, newArea, newArea/2, 4, newArea, sf::Color::White, shape.getPosition().x, shape.getPosition().y);
	}
	~Player();
	
	
	//getters
	bool vulnrable();//true=damage / false=no-damage


	//setters
	void setVulnrabile(const bool vulnrable);//true=no-damage / false=damage





	//controls
	//draw, overrides original so it can redraw weapon

	void pointToMouse(const sf::Vector2f mousePosition);
	void playerMove();
	//shoot gun


	//getters and setters for the lsit of projectiles shot

	//if weapon is shot add projectile to list for hit checking

private:
	bool isVulnrable;//true=damage / false=no-damage

	//cannonWeapon maingun;



	//list of all projectiles shot

};








