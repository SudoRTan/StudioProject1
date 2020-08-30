#pragma once
#include "Stage.h"
#include "BossStage5Alien.h"

class BossStage5
	: public Stage
{
public:
	BossStage5(Player* player);
	~BossStage5();
	void update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, int& gameState);
private:
	Enemy** aliens;
};

