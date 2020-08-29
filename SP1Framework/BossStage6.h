#pragma once
#include "Stage.h"
#include "BossStage6Police.h"

class BossStage6
	: public Stage
{
private:
	Enemy** cops;
	int numberOfCops;

public:
	BossStage6(Player* player);
	~BossStage6();

	void update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, int& gameState);
};

