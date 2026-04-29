#include "Spawner.hpp"

Spawner::Spawner()
{
	spawnTimer = 0.f;
	spawnTimerMax = 5.f;
	smallestTimeSpawnLimit = 1.f;
	currentEnemyTier = 1;
	enemiesTillNextTier = 10;
	enemyList.push_back(Grunt());
	enemyList.push_back(Jackal());
	enemyList.push_back(Brute());
	enemyList.push_back(Drone());
	enemyList.push_back(Elite());
	enemyList.push_back(Hunter());
	vectorSize = enemyList.size();
}

Spawner::~Spawner()
{

}

std::vector<Enemy>& Spawner::getAliveEnemies()
{
	return aliveEnemies;
}

void Spawner::update(float deltaTime)
{
	spawnTimer += deltaTime;
	if (spawnTimer >= spawnTimerMax) // Time to spawn an enemy
	{
		spawnTimer = 0.f; // Set time back to zero
		if (!maxTierReached) 
		{
			if (enemiesTillNextTier > 0) // Check if we need to increase the tier of the enemy
			{
				enemiesTillNextTier--;
			}
			else
			{
				enemiesTillNextTier = 10; // Reset the counter for the next tier increase
				if (currentEnemyTier < vectorSize) // Check if we can increase the tier of the enemy
				{
					currentEnemyTier++;
					std::cout << "Enemy tier increased" << std::endl;
				}
				else if (spawnTimerMax > smallestTimeSpawnLimit) // If we are at the max tier, start decreasing the spawn time
				{
					spawnTimerMax -= 0.5f; // Decrease spawn time by 0.5 seconds for each tier increase after reaching max tier
					std::cout << "Spawn time decreased" << std::endl;
				}
				else
				{
					maxTierReached = true; // We have reached the max tier and spawn time limit, we can stop increasing difficulty
					std::cout << "Max tier and spawn time reached" << std::endl;
				}
			}
		}
		spawnEnemy(enemyList,currentEnemyTier);
	}
}

void Spawner::spawnEnemy(std::vector<Enemy>& enemyList, int currentEnemyTier)
{
	int side = rand() % 4; // Randomly select a side of the screen to spawn the enemy (0 = top, 1 = bottom, 2 = left, 3 = right)
	int randomIndex = rand() % currentEnemyTier; // Randomly select an enemy from the current tier

	float x = 0.f;
	float y = 0.f;

	switch (side) // Set the position of the enemy based on the side it spawns on
	{
	case 0: // Top
		x = static_cast<float>(rand() % 1200);
		y = static_cast<float>(rand() % 100);
		break;
	case 1: // Bottom
		x = static_cast<float>(rand() % 1200);
		y = 900.f + static_cast<float>(rand() % 100);
	case 2: // Left
		x = static_cast<float>(rand() % 100);
		y = static_cast<float>(rand() % 1000);
		break;
	case 3: // Right
		x = 1100.f + static_cast<float>(rand() % 100);
		y = static_cast<float>(rand() % 1000);
		break;
	}

	aliveEnemies.push_back(enemyList[randomIndex]);
	aliveEnemies.back().setPosition(x, y);
	std::cout << "Enemy has spawned at (" << x << ", " << y << ")" << std::endl;
}
