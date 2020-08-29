#include "BossStage6Police.h"

int BossStage6Police::numberOfCops = 0;
int BossStage6Police::colcount = 0;
int BossStage6Police::rowcount = 0;

BossStage6Police::BossStage6Police() 
{
	if (rowcount >= 5)
	{
		colcount += 10;
		rowcount = 0;
	}
	position.setX(80 + colcount);
	position.setY(1 + 3 * rowcount);
	health = 2;
	updateDelay = 0.07 ;
	setDamage(8);
	direction = 0;
	rowcount++;
	numberOfCops++;
}

BossStage6Police::~BossStage6Police() 
{
	cleanUp();
	numberOfCops--;
}


int BossStage6Police::update(Map& map, double g_dElapsedTime, Player& player)
{
	patrol(map, g_dElapsedTime, player);
	return 0;
}

int BossStage6Police::getNumberOfCops()
{
	return numberOfCops;
}