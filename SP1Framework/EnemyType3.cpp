#include "EnemyType3.h"

EnemyType3::EnemyType3()
{
	height = 3;
	width = 3;

	symbolArray = createArray(width, height);

	symbolArray[0][0] = 'E';
	symbolArray[0][1] = 'E';
	symbolArray[0][2] = 'E';
	symbolArray[1][0] = 'E';
	symbolArray[1][1] = 'E';
	symbolArray[1][2] = 'E';
	symbolArray[2][0] = 'E';
	symbolArray[2][1] = 'E';
	symbolArray[2][2] = 'E';

	setHealth(2);
}

EnemyType3::EnemyType3(int x, int y)
{
	position.setX(x);
	position.setY(y);

	lastMovementTime = 0.00;
	updateDelay = 0.3;
	direction = 0;
	setDamage(1);

	height = 3;
	width = 3;

	symbolArray = createArray(width, height);

	symbolArray[0][0] = ' ';
	symbolArray[0][1] = 'E';
	symbolArray[0][2] = ' ';
	symbolArray[1][0] = 'E';
	symbolArray[1][1] = 'E';
	symbolArray[1][2] = 'E';
	symbolArray[2][0] = ' ';
	symbolArray[2][1] = 'E';
	symbolArray[2][2] = ' ';

	setHealth(2);
}

EnemyType3::~EnemyType3()
{

}

int EnemyType3::update(Map& map, double g_dElapsedTime, Player& player)
{
	return patrol(map, g_dElapsedTime, player);;
}
