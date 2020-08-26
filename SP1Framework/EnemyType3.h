#pragma once
#include "Enemy.h"
class EnemyType3
	: public Enemy
{
private:
public:
	EnemyType3();
	EnemyType3(int x, int y);
	~EnemyType3();
	int update(Map& map, double g_dElapsedTime, Player& player);
};

