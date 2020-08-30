#include "BossStage2.h"

BossStage2::BossStage2(Player* player) :Stage(player)
{
	numberOfLocusts = 15;
	locusts = new Enemy* [numberOfLocusts];
	
	//Gets player spawn position
	int playerX = player->getPositionX();
	int playerY = player->getPositionY();

	//Spawns locusts until so that they wont be in the place where the player is.
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
	// Clears the double pointer array
	for (int i = 0; i < numberOfLocusts; i++) {
		if (locusts[i] != nullptr) {
			delete locusts[i];
			locusts[i] = nullptr;

		}
	}
	delete[] locusts;
	locusts = nullptr;

}

void BossStage2::update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, int& gameState) {
	// Updates the entities in the Stage
	entityManager.update(*map, KeyEvent, g_dElapsedTime, gameState, locusts, numberOfLocusts);

	// If all the locusts are dead
	// Player wins
 	if (BossStage2Locust::getNumberOfLocusts() == 0)
	{
		gameState = FINISHED_LEVEL;
	}
}