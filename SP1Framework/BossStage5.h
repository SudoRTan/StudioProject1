#pragma once
#include "Stage.h"
#include "Player.h"
#include "BossStage5UFO.h"

class BossStage5 :
	public Stage
{
private:
	int numberOfUfo;
	Enemy**  ufo;

public:
	BossStage5(Player* player);
	~BossStage5();
	void update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, int& gameState);

	
};

