#pragma once
#include "Stage.h"
#include "BossStage5Player.h"
#include "BossStage5Alien.h"
#include "BossStage5AlienBoss.h"

class BossStage5
	: public Stage
{
public:
	BossStage5();
	~BossStage5();
	void update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, int& gameState);
private:
	Enemy** aliens;
};

