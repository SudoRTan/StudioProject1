#pragma once
#include "Player.h"
#include "Enemy.h"
#include "EntityTemplate.h"
#include "Collectible.h"
#include "game.h"
#include "Framework/console.h"
#include "Map.h"
#include "gameState.h"


class EntityManager
{
	Player* player;


	int numOfEnemies;
	int numOfCollectibles;

	Collectible** collectible;

public:
	Enemy** enemy;


	EntityManager(Player* player);
	~EntityManager();
	

	void update(Map& map, SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, int& gameState);
	void loadEnemy(int sizeOfArray, EntityTemplate** enemyTemplate);

	void loadCollectible(int sizeOfArray, EntityTemplate** collectibleTemplate);

	void cleanUp();
};

