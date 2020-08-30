#pragma once
#include "Enemy.h"

class BossStage5Alien
	: public Enemy
{
public:
	BossStage5Alien();
	~BossStage5Alien();

	int update(Map& map, double g_dElapsedTime, Player& player);
};

