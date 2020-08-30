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
	int numberOfBullets;

	int state;
	int previousHealth;

	double lastFireTime;
	double fireDelay;

	double panicStartTime;
	double panicDelay;
	double panicDuration;


	void panicMove(Map& map, double elapsedTime, Player& player);
	void normalMove(Map& map, double elapsedTime, Player& player);
	void fire(double elapsedTime, bool panic);

public:
	BossStage5UFO::BossStage5UFO(int x, int y);

	BossStage5UFO::~BossStage5UFO();

	int update(Map& map, double elapsedTime, Player& player);
};

