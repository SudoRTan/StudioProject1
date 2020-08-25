#include "EntityManager.h"


EntityManager::EntityManager(Player* player) {
	this->player = player;
	enemy = nullptr;
	collectible = nullptr;

}


EntityManager::~EntityManager() {
	cleanUp();

}


void EntityManager::update(Map& map, SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, int& gameState) {
	int playerReturnValue = player->update(map, KeyEvent, g_dElapsedTime, enemy, numOfEnemies);

	if (playerReturnValue == PLAYER_GOT_HEALTH) {
		player->resetHealth();
	}
	if (playerReturnValue == PLAYER_REACHED_DOOR) {
		gameState = FINISHED_LEVEL;
	}
	if (player->getHealth() <= 0) {
		gameState = PLAYER_DEATH;
	}
	
	if (enemy != nullptr) {
		for (int i = 0; i < numOfEnemies; i++) {
			if (enemy[i] != nullptr) {
				if (enemy[i]->getHealth() <= 0) {
					enemy[i]->death(map);
					delete enemy[i];
					enemy[i] = nullptr;
				}
				else {
					int enemyReturnValue = 0;
					enemyReturnValue = enemy[i]->update(map, g_dElapsedTime, *player);
				}
			}
		}
	}
}

void EntityManager::loadEnemy(int sizeOfArray, EnemyTemplate** enemyTemplate) {

	enemy = new Enemy * [sizeOfArray];

	numOfEnemies = sizeOfArray;


	for (int i = 0; i < sizeOfArray; i++) {
		enemy[i] = new Enemy(enemyTemplate[i]->postion.X, enemyTemplate[i]->postion.Y);
	}

}

void EntityManager::cleanUp() {
	if (enemy != nullptr) {
		for (int i = 0; i < numOfEnemies; i++) {
			if (enemy[i] != nullptr) {
				delete enemy[i];
			}
		}
		delete[] enemy;
		enemy = nullptr;
	}
}