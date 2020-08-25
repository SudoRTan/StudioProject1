#pragma once
#include "Player.h"
#include "Enemy.h"
class BossStage1Fire :
	public Enemy
{
public:
	BossStage1Fire();
	~BossStage1Fire();
	double getLastSpawnTime();
	int update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, int& gameState);
};