#pragma once
#include "Enemy.h"
class EnemyType2
	: public Enemy
{
private:
public:
	EnemyType2();
	~EnemyType2();
	int update(Map& map, double g_dElapsedTime, Player& player);
};

