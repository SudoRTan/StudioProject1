#pragma once
#include "Player.h"
#include "Enemy.h"
class BossStage1Fire :
	public Enemy
{
public:
	BossStage1Fire();
	~BossStage1Fire();
	int update(Map& map, double g_dElapsedTime, Player& player);
};