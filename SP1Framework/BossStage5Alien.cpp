#include "BossStage5Alien.h"

BossStage5Alien::BossStage5Alien()
{
	switch (rand() % 9)
	{
	case 0:
	case 4:
	case 7:
	case 9:
		health = 1;
	case 1:
	case 5:
	case 8:
		health = 2;
	case 3:
	case 6:
		health = 3;
	}
	updateDelay = 0.7;
	setDamage(20);
	height = 1;
	width = 1;
	symbolArray = createArray(width, height);
	symbolArray[0][0] = (char)69;
}

BossStage5Alien::~BossStage5Alien()
{

}

int BossStage5Alien::update(Map& map, double g_dElapsedTime, Player& player)
{
	if (position.getX() < 0)
		if (g_dElapsedTime - lastMovementTime < updateDelay)
			updateNewPosition(map, position.getX() - 1, position.getY());
	return NO_CHANGE;
}