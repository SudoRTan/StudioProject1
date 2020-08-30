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
	for (int i = 0; i < 98; i++)
	{
		delete aliens[i];
		aliens[i] = nullptr;
	}
}

void BossStage5::update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, int& gameState) 
{
	entityManager.update(*map, KeyEvent, g_dElapsedTime, gameState, aliens, 99);


}