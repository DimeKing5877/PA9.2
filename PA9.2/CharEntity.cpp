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

void CharEntity::setMoveSpeed(double newSpeed)
{
	moveSpeed = newSpeed;
}

void CharEntity::setHealth(int newHealth)
{
	health = newHealth;
}

void CharEntity::updateHealth(int damage)
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




