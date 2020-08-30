#pragma once
#include "Enemy.h"
#include "Projectile.h"

class BossStage6Police :
	public Enemy
{
private:
	Projectile* bullet;

	double fireDelay;
	double lastFireTime;

	void fire(double elapsedTime);

public:
	BossStage6Police(int x, int y, int direction);
	~BossStage6Police();

	int update(Map& map, double elapsedTime, Player& player);
};

