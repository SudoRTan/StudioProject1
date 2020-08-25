#include "BossStage1Fire.h"

BossStage1Fire::BossStage1Fire()
{
	position.setX(4 * (rand() % 5));
	position.setY(1 + 5 * (rand() % 24));
	setHealth(3);
	damageDelay = 0.1;
	cleanUp();
	height = 2;
	width = 3;
	symbolArray = createArray(width, height);
	symbolArray[0][0] = ' ';
	symbolArray[0][1] = ')';
	symbolArray[0][2] = ' ';
	symbolArray[1][0] = '(';
	symbolArray[1][1] = '_';
	symbolArray[1][2] = ')';
}

BossStage1Fire::~BossStage1Fire()
{

}

double BossStage1Fire::getLastSpawnTime()
{
	return lastSpawnTime;
}

int 