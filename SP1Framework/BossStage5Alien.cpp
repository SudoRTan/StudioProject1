#include "BossStage5Alien.h"

BossStage5Alien::BossStage5Alien()
{
	position.setX(rand() % 120);
	position.setY(1 + 3 * (rand() % 5));
	health = 4;
	updateDelay = 0.7;
	setDamage(5);
	direction = rand() % 2;
}

BossStage5Alien::~BossStage5Alien()
{

}

int BossStage5Alien::update(Map& map, double g_dElapsedTime, Player& player)
{
	patrol(map, g_dElapsedTime, player);
	return 0;
}
