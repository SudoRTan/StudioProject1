#include "BossStage3.h"

BossStage3::BossStage3(Player* player): Stage(player)
{
	maxNumberOfVirus = 1;
	virus = new Enemy* [maxNumberOfVirus];
	virus[0] = new BossStage3Virus;
}

BossStage3::~BossStage3()
{
	if (virus[0] != nullptr) {
		delete virus[0];
		virus[0] = nullptr;
	}
}

void BossStage3::update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, int& gameState)
{
	entityManager.update(*map, KeyEvent, g_dElapsedTime, gameState, virus, maxNumberOfVirus);
	
	if (virus[0] == nullptr) {
		gameState = LEVEL_COMPLETE_MENU;
	}
}