#include "BossStage6Police.h"

BossStage6Police::BossStage6Police(int xpos, int ycount) 
{
	position.setX(xpos);
	position.setY(1 + 3 * ycount);
	health = 2;
	updateDelay = 0.5;
	setDamage(8);
	direction = 0;
	ycount++;

}

BossStage6Police::~BossStage6Police() 
{

}

int BossStage6Police::update(Map& map, double g_dElapsedTime, Player& player)
{
	patrol(map, g_dElapsedTime, player);
	return 0;
}
