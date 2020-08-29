#include "BossStage4.h"

BossStage4::BossStage4(Player* player) : Stage(player)
{
	enemies = new Enemy* [2];
	enemies[0] = new BossStage4People;
	enemies[1] = new BossStage4People;
}

BossStage4::~BossStage4()
{
	for (int i = 0; i < 2; i++)
	{
		enemies[i]->cleanUp();
		delete enemies[i];
		enemies[i] = nullptr;
	}
}

void BossStage4::update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, int& gameState)
{
	if (player->getHealth() != 0)
	{
		for (int i = 0; i < 2; i++)
		{
			enemies[i]->update(*map, g_dElapsedTime, *player);
		}
	}
}