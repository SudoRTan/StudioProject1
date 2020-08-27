#include "BossStage3.h"

BossStage3::BossStage3(Player* player): Stage(player)
{
	numberOfVirus = 1;
	virus = new Enemy* [numberOfVirus];
	virus[0] = new BossStage3Virus;

}

BossStage3::~BossStage3()
{

}