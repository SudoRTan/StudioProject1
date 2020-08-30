#include "BossStage5.h"

BossStage5::BossStage5(Player* player) :Stage(player)
{
	aliens = new Enemy* [98];
}

BossStage5::~BossStage5()
{
	
}

void BossStage5::update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, int& gameState) 
{
	
}