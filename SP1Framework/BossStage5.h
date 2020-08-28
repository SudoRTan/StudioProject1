#pragma once
#include "Stage.h"
#include "BossStage5Alien.h"

class BossStage5
	: public Stage
{
private:
	Enemy** aliens;
	int numberOfAliens;
	int aliensLeft;

public:
	BossStage5(Player* player);
	~BossStage5();

	void update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, int& gameState);
};

