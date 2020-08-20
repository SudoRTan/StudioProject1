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
		delete[] enemy;
		enemy = nullptr;
	}
}



void Stage::loadMap(std::string fileName) {
	map = new Map(fileName);
	enemy = new Enemy*;
	enemy[0] = new Enemy(5,1);
	numOfEnemies = 1;
}

void Stage::update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime) {

	player->move(*map, KeyEvent, g_dElapsedTime);
	player->updateHeight(*map, g_dElapsedTime);

	if (enemy != nullptr) {
		for (int i = 0; i < numOfEnemies; i++) {
			if (enemy[i]!=nullptr) {
				enemy[i]->patrol(*map, g_dElapsedTime);
			}
		}
	}
}

void Stage::render(Console& console) {

	map->renderMap(console, player->getPositionX(), player->getPositionY());
}