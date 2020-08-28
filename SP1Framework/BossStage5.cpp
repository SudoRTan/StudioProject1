#include "BossStage5.h"

BossStage5::BossStage5(Player* player) :Stage(player)
{
	numberOfAliens = 25;
	aliens = new Enemy* [numberOfAliens];

	for (int i = 0; i < numberOfAliens; i++) {
		aliens[i] = new BossStage5Alien();
	}
}

BossStage5::~BossStage5()
{
	for (int i = 0; i < numberOfAliens; i++) {
		if (aliens[i] != nullptr) {
			delete aliens[i];
			aliens[i] = nullptr;
		}
	}

}

void BossStage5::update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, int& gameState) {
	entityManager.update(*map, KeyEvent, g_dElapsedTime, gameState, aliens, numberOfAliens);
}