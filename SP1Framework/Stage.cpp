#include "Stage.h"
#include <sstream>


Stage::Stage(Player* player) : entityManager(player) {
	this->player = player;
	map = nullptr;
	numOfEnemies = 0;
	stageNumber = 1; // player starts game at stage1_1
	levelNumber = 1;

	type = "Stage";
}

Stage::~Stage() {
	cleanUp();
}


void Stage::cleanUp(void) {
	if (map != nullptr) {
		delete map;
		map = nullptr;
	}

	entityManager.cleanUp();

}

void Stage::loadMap(int stageToLoad, int levelToLoad) {
	cleanUp();

	stageNumber = stageToLoad;
	levelNumber = levelToLoad;

	
	map = new Map(stageNumber, levelNumber);

	EntityTemplate**  enemyPositions = map->getEnemyTemplate();
	EntityTemplate** collectiblePositions = map->getCollectibleTemplate();

	numOfEnemies = map->getNumberOfEnemies();
	int numOfCollectibles = map->getNumberOfCollectibles();

	entityManager.loadCollectible(numOfCollectibles, collectiblePositions);

	entityManager.loadEnemy(numOfEnemies, enemyPositions);


	player->setPosition(map->getPlayerPosition().X, map->getPlayerPosition().Y);
	
	entityManager.init(*map);

}

 void Stage::update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, int& gameState) {



	entityManager.update(*map, KeyEvent, g_dElapsedTime, gameState);
	
	/*
	if (enemy != nullptr) {
		for (int i = 0; i < numOfEnemies; i++) {
			if (enemy[i] != nullptr) {
				if (enemy[i]->getHealth() <= 0) {
					enemy[i]->death(*map);
					delete enemy[i];
					enemy[i] = nullptr;
				}
				else {
					int enemyReturnValue = 0;
					enemyReturnValue = enemy[i]->update(*map, g_dElapsedTime, *player);
				}
			}
		}
	}
	*/
}

void Stage::render(Console& console) {
	ui.render(console, *player, stageNumber, levelNumber);
	map->renderMap(console, player->getPositionX(), player->getPositionY());
}


std::string Stage::getType() {
	return type;
}

