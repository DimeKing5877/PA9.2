#pragma once
#include "CharEntity.hpp"
#include "WeaponEntityClass.hpp"

class Player : public CharEntity {
public:
	Player(const double newMoveSpeed = 1.8, const int newHealth = 5, const int newNumOfSides = 1, const double newArea = 20, const sf::Color& newColor = sf::Color::Green)
	: CharEntity(newMoveSpeed, newHealth, newNumOfSides, newArea, newColor) 
	{
		shape.setOrigin({float(area) , float(area)});
		shape.setPosition({(int(WINDOW_WIDTH/2)- float(area)), (int(WINDOW_LENGTH/2) - float(area))});
		isVulnrable = true;
		weaponSlot = 3;
		setWeaponsPosition();
		setWeaponSize();
		bodyDamage = 1;
		invincalbeDuration = 2;
	}
	~Player();
	
	
	//getters
	bool vulnrable();//true=damage / false=no-damage
	int getWeaponSlot();//gets the weapon slot the player is on
	int getBodyDamage();
	float getInvincalbeDuration();


	//setters
	void setVulnrabile(const bool vulnrable);//true=no-damage / false=damage
	void setWeaponSlot(const int newWeaponSlot);//changes the weapon being held
	void setWeaponSlot();//changes the weapon being held
	void setBodyDamage(const int newBodyDamage);
	void resetInvincalbeDuration();
	void invincableCountDown(const float deltaTime);


	//controls
	void pointToMouse(const sf::Vector2f mousePosition);
	void playerMove(float deltatime);
	void shootGun();
	
	
	void draw(sf::RenderWindow*& window);//draw, overrides original so it can redraw weapon
	



	//getters and setters for the lsit of projectiles shot
	//if weapon is shot add projectile to list for hit checking

private:
	bool isVulnrable;//true=damage / false=no-damage
	int bodyDamage;
	float invincalbeDuration;

	int weaponSlot;//the weapon slot the players is on
	basicWeapon	mainWeapon;//the main weapon
	doubleWeapon secondWeapon;//double parel weapon
	cannonWeapon thirdWeapon;//the cannon weapon for the player
	plusWeapon fourthWeapon;//the plus weapon for the player
	lazzerWeapon fifthWeapon;//the lazzer weapon for player
	


	void setWeaponsPosition();
	void setWeaponSize();
	void rotateWeapons(sf::Angle rotation);


	//list of all projectiles shot

};








