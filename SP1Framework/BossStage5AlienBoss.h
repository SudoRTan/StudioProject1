#pragma once 
#include <vector> 
#include "Enemy.h"
#include "Projectile.h"
class BossStage5AlienBoss :
    public Enemy
{
public:
	BossStage5AlienBoss();
	~BossStage5AlienBoss();

	int update(Map& map, double g_dElapsedTime, Player& player);
private:
	int toY;
	std::vector<*Projectile> projectile;
};