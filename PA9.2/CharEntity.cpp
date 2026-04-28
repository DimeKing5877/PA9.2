#include "CharEntity.hpp"

CharEntity::~CharEntity(){
	//nothing needs to be added here
}

double CharEntity::getMoveSpeed()
{
	return moveSpeed;
}

int CharEntity::getHealth()
{
	return health;
}

void CharEntity::setMoveSpeed(const double& newSpeed)
{
	moveSpeed = newSpeed;
}

void CharEntity::setHealth(const int& newHealth)
{
	health = newHealth;
}

void CharEntity::updateHealth(const int& damage)
{
	health -= damage;
}

bool CharEntity::isDead()
{
	bool dead = false;
	if (health <= 0) {
		dead = true;
	}
	return dead;
}


//needs to be built, so the entity shape needs to be deleted 
void CharEntity::dies(){
	
}

bool CharEntity::checkHit(const sf::FloatRect& otherBox){
	bool hit = false;
	sf::FloatRect boundingBox = shape.getGlobalBounds();
	if (const std::optional intersection = boundingBox.findIntersection(otherBox))
	{
		hit = true;
	}
	return hit;
}




