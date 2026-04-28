#include "Spawner.hpp"

Spawner::Spawner()
{
	spawnTimer = 0.f;
	spawnTimerMax = 5.f;
	enemyList.push_back(Grunt());
	enemyList.push_back(Brute());
	enemyList.push_back(Drone());
}

Spawner::~Spawner()
{

}

void Spawner::update(float deltaTime)
{
	spawnTimer += deltaTime;
	if (spawnTimer >= spawnTimerMax)
	{
		spawnTimer = 0.f;
		spawnEnemy(enemyList);
	}
}

void Spawner::spawnEnemy(std::vector<Enemy>& enemyList)
{
	std::cout << "Enemy has spawned" << std::endl; // Placeholder for actual spawning logic
}
