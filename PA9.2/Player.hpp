#pragma once
#include "CharEntity.hpp"
#include "WeaponEntityClass.hpp"

class Player : public CharEntity {
public:
	Player(const double newMoveSpeed = 1.2, const int newHealth = 3, const int newNumOfSides = 1, const double newArea = 20, const sf::Color& newColor = sf::Color::White)
	: CharEntity(newMoveSpeed, newHealth, newNumOfSides, newArea, newColor) 
	{
		shape.setOrigin({float(area) , float(area)});
		shape.setPosition({(int(WINDOW_WIDTH/2)- float(area)), (int(WINDOW_LENGTH/2) - float(area))});
		isVulnrable = true;
		weaponSlot = 2;
		setWeaponsPosition();
	}
	~Player();
	
	
	//getters
	bool vulnrable();//true=damage / false=no-damage
	int getWeaponSlot();//gets the weapon slot the player is on


	//setters
	void setVulnrabile(const bool vulnrable);//true=no-damage / false=damage
	void setWeaponSlot(const int newWeaponSlot);//changes the weapon being held




	//controls
	void pointToMouse(const sf::Vector2f mousePosition);
	void playerMove();
	//shoot gun
	
	
	void draw(sf::RenderWindow*& window);//draw, overrides original so it can redraw weapon
	



	//getters and setters for the lsit of projectiles shot
	//if weapon is shot add projectile to list for hit checking

private:
	bool isVulnrable;//true=damage / false=no-damage


	int weaponSlot;//the weapon slot the players is on
	cannonWeapon mainWeapon;//the cannon weapon for the player
	plusWeapon secondWeapon;//the plus weapon for the player
	void setWeaponsPosition();


	//list of all projectiles shot

};








