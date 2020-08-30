#include "BossStage5.h"

BossStage5::BossStage5() : Stage(player)
{
	player = new BossStage5Player();
	aliens = new Enemy* [99];
	for (int i = 0; i < 98; i++)
	{
		aliens[i] = new BossStage5Alien();
	}
	aliens[98] = new BossStage5AlienBoss();
}

BossStage5::~BossStage5()
{
	for (int i = 0; i < 99; i++)
	{
		delete aliens[i];
		aliens[i] = nullptr;
	}
}

void BossStage5::update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, int& gameState) 
{
	entityManager.update(*map, KeyEvent, g_dElapsedTime, gameState, aliens, 99);

	if (getNumberOfEnemies() == 0)
	{
		gameState = FINISHED_LEVEL;
	}
}

int BossStage5::getNumberOfEnemies()
{
	int enemyCount = 0;
	for (int i = 0; i < 99; i++)
		if (aliens[i] != nullptr)
			enemyCount++;
	return enemyCount;
}