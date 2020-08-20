#pragma once
#include "Entity.h"
#include "game.h"
#include "Framework/console.h"
#include "colors.h"
#include "Enemy.h"


class Player :
	public Entity
{
private:
	int changeInHeight;
	bool dropping;
	COORD enemyLocation;

public:
	Player();
	Player(int x, int y);
	~Player();

	int move(Map& map,SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime);
	void updateHeight(Map& map, double g_dElapsedTime);
	void renderPlayer(Console& console);
	void touchEnemy(Enemy enemy, double g_dElapsedTime);

	char getItemBelow(Map& map);

	void setPosition(int x, int y);

	COORD getEnemyLocation();
};