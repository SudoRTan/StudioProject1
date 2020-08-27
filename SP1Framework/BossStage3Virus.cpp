#include "BossStage3Virus.h"

BossStage3Virus::BossStage3Virus()
{
	position.setX(118);
	position.setY(2);
	setHealth(50);
	setDamage(20);
	damageDelay = 0.3;
	cleanUp();
	height = 3;
	width = 3;
	symbolArray = createArray(width, height);
	symbolArray[0][0] = '„©';
	symbolArray[0][1] = '„¦';
	symbolArray[0][2] = '„©';
	symbolArray[1][0] = '„§';
	symbolArray[1][1] = '#';
	symbolArray[1][2] = '„¥';
	symbolArray[2][0] = '„©';
	symbolArray[2][1] = '„¨';
	symbolArray[2][2] = '„©';
	mode = 1 + 2 * (rand() % 2);
	directionMoving = 0;
	directionFacing = 1;
}

BossStage3Virus::~BossStage3Virus()
{
	cleanUp();
}

int BossStage3Virus::update(Map& map, double g_dElapsedTime, Player& player)
{
	updateNewPosition(map, position.getX(), position.getY());
	if (contactPlayer(position.getX(), position.getY(), player) == true)
		player.takeDamage(getDamage());
	
	return 0;
}