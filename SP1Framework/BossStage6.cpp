#include "BossStage6.h"

BossStage6::BossStage6(Player* player) :Stage(player)
{
	//numberOfCops = 20;
	//cops = new Enemy * [numberOfCops];

	//for (int i = 0; i < 4; i++) {
	//	for (int j = 0; j < 5; j++) {
	//		cops[j] = new BossStage6Police(80 + (i * 2), j);
	//	}
	//}
}

BossStage6::~BossStage6() {
	
	for (int i = 0; i < numberOfCops; i++) {
		if (cops[i] != nullptr) {
			delete cops[i];
			cops[i] = nullptr;
		}

	}
}

void BossStage6::update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, int& gameState)
{
	entityManager.update(*map, KeyEvent, g_dElapsedTime, gameState, cops, numberOfCops);

	//if (BossStage6Police::getNumberOfCops() == 0)
	//{
	//	gameState = LEVEL_COMPLETE_MENU;
	//}
}