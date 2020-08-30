#pragma once
#include "Stage.h"
#include "BossStage6Police.h"



class BossStage6 :
	public Stage
{
private:

	int numberOfPolice;
	int maxNumberOfPolice;

	Enemy** police;

	int numberOfPoliceLeft;
	double lastSpawnTime;
	double spawnDelay;


public:
	BossStage6(Player* player);
	~BossStage6();

	void update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, int& gameState);


};

