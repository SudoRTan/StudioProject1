#include "BossStage1Fire.h"

int BossStage1Fire::currNumberOfFires = 0;

BossStage1Fire::BossStage1Fire(int x, int y)
{
	position.setX(x);
	position.setY(y);
	setHealth(2);
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

	currNumberOfFires++;
}

BossStage1Fire::~BossStage1Fire()
{
	currNumberOfFires--;
	cleanUp();
}

int BossStage1Fire::update(Map& map, double g_dElapsedTime, Player& player)
{
	updateNewPosition(map, position.getX(), position.getY());

	if (contactPlayer(position.getX(), position.getY(), player)) {
		player.takeDamage(getDamage());
	}
	return 0;
}


int BossStage1Fire::getNumberOfFires() {
	return currNumberOfFires;
}