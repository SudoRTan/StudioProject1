#include "BossStage6.h"

BossStage6::BossStage6(Player* player) :Stage(player)
{
	numberOfCops = 15;
	cops = new Enemy* [numberOfCops];
	
	for (int i = 0; i < numberOfCops; i++) {
		if (i < 5) {
			cops[i] = new BossStage6Police(80, i);
		}
		else if (i < 10) {
			cops[i] = new BossStage6Police(90, 9 - i);
		}
		else {
			cops[i] = new BossStage6Police(100, 14 - i);
		}
	}
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
}