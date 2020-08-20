#include "Stage.h"


Stage::Stage() {
	player = new Player;
	map = nullptr;
	enemy = nullptr;
	numOfEnemies = 0;
}

Stage::~Stage() {
	if (player != nullptr) {
		delete player;
		player = nullptr;
	}
	if (map != nullptr) {
		delete map;
		map = nullptr;
	}
	if (enemy != nullptr) {
		for (int i = 0; i < numOfEnemies; i++) {
			delete enemy[i];
		}
		delete[] enemy;
		enemy = nullptr;
	}
	int stop = 3;
}



void Stage::loadMap(std::string fileName) {
	if (map == nullptr) {
		map = new Map(fileName);

	}
	else {
		delete map;
		map = new Map(fileName);

	}
	
	numOfEnemies = map->getNumberOfEnemies();

	COORD** enemyPosition = map->getPositionOfEnemies();

	char* enemySymbol = map->getSymbolOfEnemies();

	player->setPosition(map->getPlayerPosition().X, map->getPlayerPosition().Y);

	enemy = new Enemy * [numOfEnemies];

	for (int i = 0; i < numOfEnemies; i++) {
		enemy[i] = new Enemy(enemyPosition[i]->X, enemyPosition[i]->Y);

	}
	

}

void Stage::update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime) {

	int playerReturnValue = player->move(*map, KeyEvent, g_dElapsedTime);
	player->updateHeight(*map, g_dElapsedTime);
	
	if (playerReturnValue == PLAYER_DAMAGED) {
		Enemy* attackingEnemy = getEnemy(player->getEnemyLocation().X, player->getEnemyLocation().Y);
		player->takeDamage(attackingEnemy->getDamage());
	}
	/*
	switch (playerReturnValue) {
	case PLAYER_DAMAGED:
		break;
	default:
		break;
	}
	*/


	if (enemy != nullptr) {
		for (int i = 0; i < numOfEnemies; i++) {
			int enemyReturnValue = 0;

			if (enemy[i]!=nullptr) {
				enemyReturnValue = enemy[i]->patrol(*map, g_dElapsedTime);
			}

			switch (enemyReturnValue) {
			case PLAYER_DAMAGED:
				player->takeDamage(enemy[i]->getDamage());
				break;
			default:
				break;
			}
		}
	}
}

void Stage::render(Console& console) {
	ui.render(console, *player);
	map->renderMap(console, player->getPositionX(), player->getPositionY());
}


Enemy* Stage::getEnemy(int x, int y) {
	Enemy* returnEnemy = nullptr;
	
	
	for (int i = 0; i < numOfEnemies; i++) {
		if (enemy[i]->getPositionX() == x && enemy[i]->getPositionY() == y) {
			returnEnemy = enemy[i];
		}

	}
	return returnEnemy;
}