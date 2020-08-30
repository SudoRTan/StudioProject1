#include "BossStage5.h"

BossStage5::BossStage5(Player* player) :Stage(player)
{
	aliens = new Enemy* [98];
}

BossStage5::~BossStage5()
{
	for (int i = 0; i < 98; i++)
	{
		delete aliens[i];
		aliens[i] = nullptr;
	}
}

void BossStage5::update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, int& gameState) 
{
	entityManager.update();
}