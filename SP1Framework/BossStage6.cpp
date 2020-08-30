#include "BossStage6.h"


BossStage6::BossStage6(Player* player) : Stage(player){

	numberOfPolice = 20;

	maxNumberOfPolice = 10;


	numberOfPoliceLeft = numberOfPolice;

	police = new Enemy * [maxNumberOfPolice];

	for (int i = 0; i < maxNumberOfPolice; i++) {
		police[i] = nullptr;
	}
	
	lastSpawnTime = 0;
	spawnDelay = 2;
}

BossStage6::~BossStage6() {
	cleanUp();
}

void BossStage6::update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, int& gameState) {
	
	if (g_dElapsedTime - lastSpawnTime > spawnDelay) {
		int i = 0;
		while (i < maxNumberOfPolice) {
			if (police[i] == nullptr) {
				lastSpawnTime = g_dElapsedTime;
				switch (rand() % 2) {
				case LEFT:
					police[i] = new BossStage6Police(79, 1 + 3 * ( rand() % 5), LEFT);
					break;
				default:
					police[i] = new BossStage6Police(0, 1 + 3 * (rand() % 5), RIGHT);
					break;
				}
				numberOfPoliceLeft--;
				break;
			}
			i++;
		}
	}
	
	entityManager.update(*map, KeyEvent, g_dElapsedTime, gameState, police, maxNumberOfPolice) ;


	
}