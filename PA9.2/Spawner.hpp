#pragma once

#include "BasicEnemies.hpp"

class Spawner
{
public:
	Spawner();
	~Spawner();
	void update(float deltaTime);
	void spawnEnemy(std::vector<Enemy>& enemyList);
private:
	float spawnTimer;
	float spawnTimerMax;
	std::vector<Enemy> enemyList;
};