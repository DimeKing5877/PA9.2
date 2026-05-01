#pragma once
#include "CharEntity.hpp"
#include "WeaponEntityClass.hpp"

#define WEAPON_SPEED1 1
#define WEAPON_SPEED2 .5
#define WEAPON_SPEED3 5
#define WEAPON_SPEED4 2
#define WEAPON_SPEED5 10


class Player : public CharEntity {
public:
	Player(const double newMoveSpeed = 1.8, const int newHealth = 6, const int newNumOfSides = 1, const double newArea = 20, const sf::Color& newColor = sf::Color::Green)
	: CharEntity(newMoveSpeed, newHealth, newNumOfSides, newArea, newColor) 
	{
		shape.setOrigin({float(area) , float(area)});
		shape.setPosition({(int(WINDOW_WIDTH/2)- float(area)), (int(WINDOW_LENGTH/2) - float(area))});
		isVulnrable = true;
		weaponSlot = 1;
		setWeaponsPosition();
		setWeaponSize();
		bodyDamage = 3;
		invincalbeDuration = 2;


		//weapon base cooldown
		mainWeaponRest = 0;
		secondWeaponRest = 0;
		thirdWeaponRest = 0;
		fourthWeaponRest = 0;
		fifthWeaponRest = 0;
		evenShot = 0;
		lazerDeration = WEAPON_SPEED2;
	}
	~Player();
	
	
	//getters
	bool vulnrable();//true=damage / false=no-damage
	int getWeaponSlot();//gets the weapon slot the player is on
	float getInvincalbeDuration();


	//setters
	void setVulnrabile(const bool& vulnrable);//true=no-damage / false=damage
	void setWeaponSlot(const int& newWeaponSlot);//changes the weapon being held
	void setWeaponSlot();//changes the weapon being held
	void resetInvincalbeDuration();
	void invincableCountDown(const float& deltaTime);


	//controls
	void pointToMouse(const sf::Vector2f& mousePosition);//poins player to mouse
	void playerMove(const float& deltatime);//moves player
	void shootGun(const sf::Vector2f& mousePosition, const float& deltatime);//shoots equiped weapon
	
	
	void draw(sf::RenderWindow*& window);//draw, overrides original so it can redraw weapon
	
	basicWeapon& getMainWeapon();//the main weapon
	doubleWeapon& getSecondWeapon();//double parel weapon
	cannonWeapon& getThirdWeapon();//the cannon weapon for the player
	plusWeapon& getFourthWeapon();//the plus weapon for the player
	lazzerWeapon& getFifthWeapon();//the lazzer weapon for player




	//getters and setters for the lsit of projectiles shot
	//if weapon is shot add projectile to list for hit checking

private:
	bool isVulnrable;//true=damage / false=no-damage
	float invincalbeDuration;//duration of invulnrability 

	int weaponSlot;//the weapon slot the players is on
	basicWeapon	mainWeapon;//the main weapon
	doubleWeapon secondWeapon;//double parel weapon
	cannonWeapon thirdWeapon;//the cannon weapon for the player
	plusWeapon fourthWeapon;//the plus weapon for the player
	lazzerWeapon fifthWeapon;//the lazzer weapon for player
	

	int evenShot;
	float mainWeaponRest;//main weapon cooldown
	float secondWeaponRest;//second weapon cooldown
	float thirdWeaponRest;//third weapon cooldown
	float fourthWeaponRest;//fourth weapon cooldown
	float fifthWeaponRest;//fifth weapon cooldown
	void allWeaponCoolDowns(float deltaTime);//counts down all cooldowns
	float lazerDeration;//the duration the lazer fires for

	void setWeaponsPosition();//moves weapons with player
	void setWeaponSize();//sets the seze to fit with player
	void rotateWeapons(sf::Angle rotation);//rotates weapons with player
};








