#pragma once
#include "Map.h"
#include "Enemy.h"
#include "Player.h"
#include "game.h"
#include "UI.h"
#include "Framework/console.h"
#include "gameState.h"



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

	std::string type;

	void cleanUp(void);

public:
	Stage(Player* player);
	virtual ~Stage();

	std::string getStage(void);


	void loadMap(std::string fileName);

	void update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, int& gameState);

	void render(Console& console);

	std::string getType();


};


