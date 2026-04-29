#include "Enemy.hpp"

Enemy::~Enemy()
{

}

// Enemies currently instanlty rotate once their inside the player currently
void Enemy::update(const sf::Vector2f playerPosition, float deltatime)
{
	sf::Vector2f enemyPosition = shape.getPosition();
	sf::Vector2f direction = playerPosition - enemyPosition;
	float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

	if (distance > 1.0f)
	{
		direction /= distance;
		shape.move(direction * static_cast<float>(moveSpeed) * deltatime); 
		float angle = std::atan2(direction.y, direction.x);
		shape.setRotation(sf::radians(angle));
	}
}

float Enemy::randomPosition()
{
	
}