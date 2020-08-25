#include "EnemyType2.h"

EnemyType2::EnemyType2()
{
	height = 2;
	width = 1;

	symbolArray = createArray(width, height);

	symbolArray[0][0] = 'E';
	symbolArray[0][1] = 'E';

	setHealth(2);
}

EnemyType2::~EnemyType2()
{

}

int EnemyType2::update(Map& map, double g_dElapsedTime, Player& player)
{
	return patrol(map, g_dElapsedTime, player);
}
