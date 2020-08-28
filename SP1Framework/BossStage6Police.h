#pragma once
#include "Enemy.h"

class BossStage6Police
	: public Enemy
{
private:
	static int numberOfCops;

public:
	BossStage6Police(int xpos, int ycount);
	~BossStage6Police();

	int update(Map& map, double g_dElapsedTime, Player& player);
	static int getNumberOfCops();
};

