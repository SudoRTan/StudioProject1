#include "Stage.h"
#include <sstream>


Stage::Stage() {
	player = new Player;
	map = nullptr;
	enemy = nullptr;
	numOfEnemies = 0;
	stageNumber = 1; // player starts game at stage1_1
	levelNumber = 1;
	currentStage = "stage1_1.txt";
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
}

std::string Stage::getStage(void)
{
	return currentStage;
}

void Stage::updateStage(void)
{
	/*
	if (player->reachDoor() == true)
	{
		std::ostringstream ss;
		ss.str("");
		levelNumber++;

		if (levelNumber == 4)
		{
			ss << "stage" << stageNumber << "_" << "B" << ".txt";
			stageNumber++;
			levelNumber = 0;
		}
		else
		{
			ss << "stage" << stageNumber << "_" << levelNumber << ".txt";
		}

		currentStage = ss.str(); // convert text from stringstream to string
	}
	*/
}

void Stage::loadMap(std::string fileName) {
	/*
	if (player->reachDoor() == true)
	{
		levelNumber++;
		if (levelNumber == 4)
		{

		}
		else
		{

		}
	}
	if (levelNumber == 4)
	{
		stageNumber++;
		levelNumber = 0;
	}
	*/

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

void Stage::update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, int& gameState) {

	int playerReturnValue = player->update(*map, KeyEvent, g_dElapsedTime, enemy, numOfEnemies);

	if (playerReturnValue == PLAYER_REACHED_DOOR) {
		gameState = FINISHED_LEVEL;
	}

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
}

void Stage::render(Console& console) {
	ui.render(console, *player);
	map->renderMap(console, player->getPositionX(), player->getPositionY());
}


