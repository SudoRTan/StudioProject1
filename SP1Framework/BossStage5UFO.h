#pragma once
#include "Enemy.h"
#include "Player.h"
#include "Projectile.h"

enum UFO_STATE {
	UFO_NORMAL,
	UFO_PANIC,
};

class BossStage5UFO :
	public Enemy
{
private:
	Projectile** bullets;

	int state;

	double lastFireTime;
	double fireDelay;

	double panicStartTime;
	double panicDuration;


	void normalMove(Map& map, double elapsedTime, Player& player);
	void fire(double elapsedTime);

public:
	BossStage5UFO::BossStage5UFO(int x, int y);

	BossStage5UFO::~BossStage5UFO();

	int update(Map& map, double elapsedTime, Player& player);
};

