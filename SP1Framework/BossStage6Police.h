#pragma once
#include "Enemy.h"

class BossStage6Police
	: public Enemy
{
private:

public:
	BossStage6Police(int xpos, int ycount);
	~BossStage6Police();

	virtual int update(Map& map, double g_dElapsedTime, Player& player);
};

