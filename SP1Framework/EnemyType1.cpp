#include "EnemyType1.h"

EnemyType1::EnemyType1()
{
	height = 1;
	width = 1;

	symbolArray = createArray(width, height);

	symbolArray[0][0] = 'E';

	setHealth(2);
}

EnemyType1::EnemyType1(int x, int y)
{
	position.setX(x);
	position.setY(y);

	lastMovementTime = 0.00;
	updateDelay = 0.3;
	direction = 0;
	setDamage(1);

	height = 1;
	width = 1;

	symbolArray = createArray(width, height);

	symbolArray[0][0] = 'E';

	setHealth(2);

}

EnemyType1::~EnemyType1()
{

}

int EnemyType1::update(Map& map, double g_dElapsedTime, Player& player)
{
	return patrol(map, g_dElapsedTime, player);;
}
