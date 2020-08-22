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
	player->attack(*map, KeyEvent, g_dElapsedTime, enemy, numOfEnemies);

	
	if (playerReturnValue == PLAYER_DAMAGED) {
		Enemy* attackingEnemy = getEnemy(player->getEnemyLocation().X, player->getEnemyLocation().Y, enemy, numOfEnemies);
		player->takeDamage(attackingEnemy->getDamage(), g_dElapsedTime);
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
				enemyReturnValue = enemy[i]->update(*map, g_dElapsedTime);
			}

			switch (enemyReturnValue) {
			case PLAYER_DAMAGED:
				player->takeDamage(enemy[i]->getDamage(), g_dElapsedTime);
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


