#include "BossStage2.h"

BossStage2::BossStage2(Player* player) :Stage(player)
{
	numberOfLocusts = 5;
	locusts = new Enemy* [numberOfLocusts];
	
	for (int i = 0; i < numberOfLocusts; i++) {
		locusts[i] = new BossStage2Locust();
	}
}

BossStage2::~BossStage2()
{
	for (int i = 0; i < numberOfLocusts; i++) {
		if (locusts[i] != nullptr) {
			delete locusts[i];
			locusts[i] = nullptr;

		}
	}
}

void BossStage2::update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, int& gameState) {
	entityManager.update(*map, KeyEvent, g_dElapsedTime, gameState, locusts, numberOfLocusts);
}