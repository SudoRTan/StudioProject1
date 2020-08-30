#include "BossStage5.h"

BossStage5::BossStage5(Player* player) : Stage(player) {
	numberOfUfo = 1;
	ufo = new Enemy*[numberOfUfo];

	ufo[0] = new BossStage5UFO(77, 13);

}
BossStage5::~BossStage5() {
	for (int i = 0; i < numberOfUfo; i++) {
		if (ufo[i] != nullptr) {
			delete ufo[i];
			ufo[i] = nullptr;
		}
	}
	delete[] ufo;
	ufo = nullptr;
}

void BossStage5::update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, int& gameState) {
	
	entityManager.update(*map, KeyEvent, g_dElapsedTime, gameState, ufo, numberOfUfo);
	
	if (ufo[0] == nullptr) {
		gameState = FINISHED_LEVEL;
	}
}