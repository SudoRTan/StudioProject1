#include "BossStage1Fire.h"

BossStage1Fire::BossStage1Fire()
{
	position.setX(1 + 4 * (rand() % 5));
	position.setY(2 + 5 * (rand() % 24));
	setHealth(2);
}

BossStage1Fire::~BossStage1Fire()
{

}