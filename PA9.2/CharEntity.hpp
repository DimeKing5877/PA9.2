#pragma once
#include "BasicShapes.hpp"
//#include  
#define BASE_SPEED 2

//parent to player and enemy classes
class CharEntity : public Shape {
public:
	CharEntity(const double newMoveSpeed,const int newHealth,const int newNumOfSides, const double newArea, const sf::Color& newColor) 
	: Shape(newNumOfSides, newArea, newColor)
	{
		moveSpeed = BASE_SPEED * newMoveSpeed;//multiplyer of the base speed
		health = newHealth;
	}
	virtual ~CharEntity();


	//getters
	double getMoveSpeed();
	int getHealth();

	//setters
	void setMoveSpeed(const double& newSpeed);
	void setHealth(const int& newHealth);


	void updateHealth(const int& damage);//updates the heath with damage
	bool isDead();//checks if the entity is dead or not with health
	void dies();//precodition: the entity is Dead.

	bool checkHit(const sf::FloatRect& otherBox);



protected:
	double moveSpeed;//the speed the entitys move
	int health;//the health of the entitys

private:
};




