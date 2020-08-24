#pragma once
#include "Map.h"
#include "Enemy.h"
#include "Player.h"
#include "game.h"
#include "UI.h"
#include "Framework/console.h"

class Stage
{
private:
	Map* map;
	Player* player;
	Enemy** enemy;
	int numOfEnemies;
	int stageNumber;
	int levelNumber;
	UI ui;
	std::string currentStage;


public:
	Stage();
	~Stage();

	std::string getStage(void);

	void updateStage(void);

	void loadMap(std::string fileName);

	int update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime);

	void render(Console& console);


};


