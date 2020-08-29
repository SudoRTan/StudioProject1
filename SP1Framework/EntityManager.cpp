#include "EntityManager.h"


EntityManager::EntityManager(Player* player) {
	this->player = player;
	enemy = nullptr;
	collectible = nullptr;

}


EntityManager::~EntityManager() {
	cleanUp();

}


void EntityManager::update(Map& map, SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, int& gameState, Enemy** overriddenEnemy, int numberOfOverriddenEnemy) {
	int playerReturnValue = 0;
	if (overriddenEnemy != nullptr && numberOfOverriddenEnemy != 0) {
		playerReturnValue = player->update(map, KeyEvent, g_dElapsedTime, overriddenEnemy, numberOfOverriddenEnemy, collectible, numOfCollectibles);

	}
	else {
		playerReturnValue = player->update(map, KeyEvent, g_dElapsedTime, enemy, numOfEnemies, collectible, numOfCollectibles);

	}

	if (playerReturnValue == PLAYER_GOT_HEALTH) {
		player->resetHealth();
	}
	if (playerReturnValue == PLAYER_REACHED_DOOR) {
		gameState = FINISHED_LEVEL;
	}
	if (player->getHealth() <= 0) {
		gameState = PLAYER_DEATH;
		PlaySound(TEXT("./Sounds/deathSound.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}
	if (overriddenEnemy != nullptr && numberOfOverriddenEnemy != 0) {
		for (int i = 0; i < numberOfOverriddenEnemy; i++) {
			if (overriddenEnemy[i] != nullptr) {
				if (overriddenEnemy[i]->getHealth() <= 0) {
					overriddenEnemy[i]->death(map);
					delete overriddenEnemy[i];
					overriddenEnemy[i] = nullptr;
				}
				else {
					int enemyReturnValue = 0;
					enemyReturnValue = overriddenEnemy[i]->update(map, g_dElapsedTime, *player);
				}
			}
		}
	}

	else if (enemy != nullptr) {
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

	if (collectible != nullptr) {
		for (int i = 0; i < numOfCollectibles; i++) {
			if (collectible[i] != nullptr) {
				if (collectible[i]->isCollected()) {
					delete collectible[i];
					collectible[i] = nullptr;
				}
				else {
					collectible[i]->update(map);

				}
			}
		}
	}
}

void EntityManager::loadEnemy(int sizeOfArray, EntityTemplate** enemyTemplate) {

	enemy = new Enemy * [sizeOfArray];

	numOfEnemies = sizeOfArray;


	for (int i = 0; i < sizeOfArray; i++) {
		switch (enemyTemplate[i]->symbol) {
		case 'E':
			enemy[i] = new Enemy(enemyTemplate[i]->postion.X, enemyTemplate[i]->postion.Y);
			break;
			
		case '1':
			enemy[i] = new EnemyType1(enemyTemplate[i]->postion.X, enemyTemplate[i]->postion.Y);
			break;

		case '2':
			enemy[i] = new EnemyType2(enemyTemplate[i]->postion.X, enemyTemplate[i]->postion.Y);
			break;

		case '3':
			enemy[i] = new EnemyType3(enemyTemplate[i]->postion.X, enemyTemplate[i]->postion.Y);
			break;

		default:
			break;
		}
	}

}


void EntityManager::loadCollectible(int sizeOfArray, EntityTemplate** collectibleTemplate) {

	collectible = new Collectible * [sizeOfArray];

	numOfCollectibles = sizeOfArray;


	for (int i = 0; i < sizeOfArray; i++) {
		switch (collectibleTemplate[i]->symbol) {
		case HEALTH:
		case AMMO:
		case SWORD:
		case GUN:
			collectible[i] = new Collectible(collectibleTemplate[i]->postion.X, collectibleTemplate[i]->postion.Y, collectibleTemplate[i]->symbol);
			break;

		default:
			break;
		}
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

	if (collectible != nullptr) {
		for (int i = 0; i < numOfCollectibles; i++) {
			if (collectible[i] != nullptr) {
				delete collectible[i];
			}
		}
		delete[] collectible;
		collectible = nullptr;
	}

}

void EntityManager::init(Map& map) {
	if (enemy != nullptr) {
		for (int i = 0; i < numOfEnemies; i++) {
			if (enemy[i] != nullptr) {
				enemy[i]->init(map);
			}
		}
	}
	if (collectible != nullptr) {
		for (int i = 0; i < numOfCollectibles; i++) {
			if (collectible[i] != nullptr) {
				collectible[i]->init(map);
			}
		}
	}
	if (player != nullptr) {
		player->init(map);
	}

}