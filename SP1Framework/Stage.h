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
	UI ui;


public:
	Stage();
	~Stage();

	void loadMap(std::string fileName);

	void update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime);

	void render(Console& console);


};


Enemy* getEnemy(int x, int y, Enemy** enemy, int arraySize);
