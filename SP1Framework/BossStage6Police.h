#pragma once
#include "Enemy.h"

class BossStage6Police
	: public Enemy
{
private:
	static int numberOfCops;
	static int rowcount;
	static int colcount;

public:
	BossStage6Police();
	~BossStage6Police();

	int update(Map& map, double g_dElapsedTime, Player& player);
	static int getNumberOfCops();
};

