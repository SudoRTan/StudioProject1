#pragma once
#include "Enemy.h"
#include "Player.h"
class BossStage3Virus :
	public Enemy
{
public:
	BossStage3Virus();
	~BossStage3Virus();
	int update(Map& map, double g_dElapsedTime, Player& player);
};