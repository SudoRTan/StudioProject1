#include "BossStage5.h"

BossStage5::BossStage5(Player* player) : Stage(player) {
	numberOfUfo = 1;
	ufo = new Enemy*[numberOfUfo];

	ufo[0] = new BossStage5UFO(0, 13);

}
BossStage5::~BossStage5() {
}

void BossStage5::update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, int& gameState) {
	
	entityManager.update(*map, KeyEvent, g_dElapsedTime, gameState, ufo, numberOfUfo);
	

}