#include "BossStage1Fire.h"

BossStage1Fire::BossStage1Fire(int x, int y)
{
	position.setX(x);
	position.setY(y);
	setHealth(3);
	setDamage(20);
	damageDelay = 0.1;
	cleanUp();
	height = 2;
	width = 3;
	symbolArray = createArray(width, height);
	symbolArray[0][0] = '(';
	symbolArray[0][1] = '_';
	symbolArray[0][2] = ')';
	symbolArray[1][0] = ' ';
	symbolArray[1][1] = ')';
	symbolArray[1][2] = ' ';
	if (position.getX() != 1)
		canSpawnLeft = true;
	else
		canSpawnLeft = false;
	if (position.getX() != 119)
		canSpawnRight = true;
	else
		canSpawnRight = false;
}

BossStage1Fire::~BossStage1Fire()
{
	cleanUp();
}

int BossStage1Fire::update(Map& map, double g_dElapsedTime, Player& player)
{
	updateNewPosition(map, position.getX(), position.getY());
	if (contactPlayer(position.getX(), position.getY(), player) == true)
		player.takeDamage(20);
	return 0;
}

bool BossStage1Fire::getCanSpawnLeft()
{
	return canSpawnLeft;
}

void BossStage1Fire::setCanSpawnLeft(bool newBool)
{
	canSpawnLeft = newBool;
}

bool BossStage1Fire::getCanSpawnRight()
{
	return canSpawnRight;
}

void BossStage1Fire::setCanSpawnRight(bool newBool)
{
	canSpawnRight = newBool;
}

void BossStage1Fire::updateSpawnBool(Map* map)
{
	if (map->getItem(position.getX() - 3, position.getY()) == ' ')
		canSpawnLeft = true;
	else
		canSpawnLeft = false;
	if (map->getItem(position.getX() + 3, position.getY()) == ' ')
		canSpawnRight = true;
	else
		canSpawnRight = false;
}