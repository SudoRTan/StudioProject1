#include "EnemyType3.h"

EnemyType3::EnemyType3()
{
	height = 2;
	width = 2;

	symbolArray = createArray(width, height);

	symbolArray[0][0] = 'E';
	symbolArray[1][0] = ' ';
	symbolArray[0][1] = 'E';
	symbolArray[1][1] = 'E';

	setHealth(2);
}

EnemyType3::~EnemyType3()
{

}

int EnemyType3::update(Map& map, double g_dElapsedTime, Player& player)
{
	return patrol(map, g_dElapsedTime, player);;
}
