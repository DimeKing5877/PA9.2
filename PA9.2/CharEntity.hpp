#pragma once
#include "BasicShapes.hpp"
//#include  
#define BASE_SPEED 5

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
	void setMoveSpeed(double newSpeed);
	void setHealth(int newHealth);


	void updateHealth(int damage);//updates the heath with damage
	bool isDead();//checks if the entity is dead or not with health
	void dies();//precodition: the entity is Dead.

protected:
	double moveSpeed;//the speed the entitys move
	int health;//the health of the entitys

private:
};




