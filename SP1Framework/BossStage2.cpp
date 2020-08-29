#include "BossStage2.h"

BossStage2::BossStage2(Player* player) :Stage(player)
{
	numberOfLocusts = 5;
	locusts = new Enemy* [numberOfLocusts];
	
	int playerX = player->getPositionX();
	int playerY = player->getPositionY();

	for (int i = 0; i < numberOfLocusts; i++) {
		int locustX, locustY;
		do {
			locustX = rand() % 120;
			locustY = 2 + 3 * (rand() % 5);
		} while (playerX == locustX || playerY == locustY);
		
		locusts[i] = new BossStage2Locust(locustX, locustY);
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

 	if (BossStage2Locust::getNumberOfLocusts() == 0)
	{
		gameState = LEVEL_COMPLETE_MENU;
	}
}