#include "BossStage2Locust.h"

BossStage2Locust:: BossStage2Locust()
{
	position.setX(rand() % 120);
	position.setY(1 + 3 * (rand() % 5));
	health = 2;
	updateDelay = 0.001;
	setDamage(10);
	direction = rand() % 2;
}

BossStage2Locust::~BossStage2Locust()
{

}


int BossStage2Locust::update(Map& map, double g_dElapsedTime, Player& player) {
	patrol(map, g_dElapsedTime, player);
	return 0;
}

/*
void BossStage2Locust::death(Map& map) {


}
*/