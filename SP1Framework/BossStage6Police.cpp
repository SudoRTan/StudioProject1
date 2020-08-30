#include "BossStage6Police.h"

int BossStage6Police::numberOfCops = 0;

BossStage6Police::BossStage6Police(int x) 
{
	position.setX(x);
	position.setY(1 + 3 * (rand() % 5));
	health = 10;
	updateDelay = 0.7;
	lastShootTime = 0;
	setDamage(5);
	if (x == 0)
		direction = RIGHT;
	else
		direction = LEFT;
	numberOfCops++;
}

BossStage6Police::~BossStage6Police() 
{
	cleanUp();
	numberOfCops--;
}

int BossStage6Police::update(Map& map, double g_dElapsedTime, Player& player)
{
	
}

int BossStage6Police::getNumberOfCops()
{
	return numberOfCops;
}