#pragma once
#include <vector>
#include "Enemy.h"
#include "Player.h"
#include "Projectile.h"

class BossStage5UFO :
	public Enemy
{
private:
	int toY;
	double lastFireTime;
	std::vector<Projectile*> projectile;

public:
	BossStage5UFO::BossStage5UFO();
	BossStage5UFO::~BossStage5UFO();

	int update(Map& map, double elapsedTime, Player& player);
};

