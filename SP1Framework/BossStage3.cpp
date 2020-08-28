#include "BossStage3.h"

BossStage3::BossStage3(Player* player): Stage(player)
{
	numberOfVirus = 1;
	virus = new Enemy* [numberOfVirus];
	maxNumberOfVirus = 1;
	virus[0] = new BossStage3Virus;
}

BossStage3::~BossStage3()
{

}

void BossStage3::update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, int& gameState)
{
	entityManager.update(*map, KeyEvent, g_dElapsedTime, gameState, virus, numberOfVirus);
	
	for (int i = 0; i < maxNumberOfVirus; i++)
	{
		if (virus != nullptr)
			virus[i]->update(*map, g_dElapsedTime, *player);
		else
			numberOfVirus--;
	}

	if (numberOfVirus == 0)
		gameState = LEVEL_COMPLETE_MENU;
}