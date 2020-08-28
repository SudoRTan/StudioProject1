#pragma once
#include "Player.h"
#include "Enemy.h"
class BossStage1Fire :
	public Enemy
{

private:
	static int currNumberOfFires;

public:
	BossStage1Fire(int x, int y);
	~BossStage1Fire();

	int update(Map& map, double g_dElapsedTime, Player& player);
	static int getNumberOfFires();
};
