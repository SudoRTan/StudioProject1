#include "BossStage3.h"

BossStage3::BossStage3(Player* player): Stage(player)
{
	// Spawns a new Virus boss
	maxNumberOfVirus = 1;
	virus = new Enemy* [maxNumberOfVirus];
	virus[0] = new BossStage3Virus;
}

BossStage3::~BossStage3()
{ // Clears the virus pointer array
	if (virus[0] != nullptr) {
		delete virus[0];
		virus[0] = nullptr;
	}
}

void BossStage3::update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, int& gameState)
{
	// Update all the entities inside the stage
	entityManager.update(*map, KeyEvent, g_dElapsedTime, gameState, virus, maxNumberOfVirus);
	
	// End level if virus is dead.
	if (virus[0] == nullptr) {
		gameState = FINISHED_LEVEL;
	}
}