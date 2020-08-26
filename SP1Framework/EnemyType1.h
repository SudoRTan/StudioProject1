#pragma once
#include "Enemy.h"
class EnemyType1
	: public Enemy
{
private:
public:
	EnemyType1();
	EnemyType1(int x, int y);
	~EnemyType1();
	int update(Map& map, double g_dElapsedTime, Player& player);

};

