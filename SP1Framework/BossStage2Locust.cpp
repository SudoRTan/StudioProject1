#include "BossStage2Locust.h"

BossStage2Locust::BossStage2Locust()
{
	position.setX(rand() % 15);
	position.setY(rand() % 2);
	health = 2;
	updateDelay = 0.1;
}

BossStage2Locust::~BossStage2Locust()
{

}