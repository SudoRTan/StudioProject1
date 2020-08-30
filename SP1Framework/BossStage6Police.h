#pragma once
#include <vector>
#include "Enemy.h"
#include "Projectile.h"

class BossStage6Police
	: public Enemy
{
public:
	BossStage6Police(int x);
	~BossStage6Police();

	int update(Map& map, double g_dElapsedTime, Player& player);
	static int getNumberOfCops();

private:
	static int numberOfCops;
	int lastShootTime;
	std::vector<Projectile*> projectile;
};

