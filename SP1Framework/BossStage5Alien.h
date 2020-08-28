#pragma once
#include "Enemy.h"

class BossStage5Alien
	: public Enemy
{
private:

public:
	BossStage5Alien();
	~BossStage5Alien();

	virtual int update(Map& map, double g_dElapsedTime, Player& player);
};

