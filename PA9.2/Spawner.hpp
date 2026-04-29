#pragma once

#include "BasicEnemies.hpp"

class Spawner
{
public:
	Spawner();
	~Spawner();
	
	std::vector<Enemy>& getAliveEnemies();

	void update(float deltaTime);
	void spawnEnemy(std::vector<Enemy>& enemyList, int currentEnemyTier);

private:
	// Time Limit Variables
	float spawnTimer;
	float smallestTimeSpawnLimit;
	float spawnTimerMax;

	// Enemy Tier Variables
	bool maxTierReached;
	int enemiesTillNextTier; // Number of enemies that need to be spawned before the next tier of enemy is spawned or time limit cut
	int currentEnemyTier;

	// Vector Variables
	std::vector<Enemy> enemyList;
	std::vector<Enemy> aliveEnemies;
	int vectorSize;
};