#pragma once
#include "Enemy.h"
#include "Projectile.h"
#include "Player.h"

enum POLICE_STATE {
	POLICE_SHOOTING,
	POLICE_MOVING
};

class BossStage6Police :
	public Enemy
{
private:
	int state;

	int futureY;
	double lastMovementTime;
	double updateDelay;



	Projectile* bullet;

	double fireDelay;
	double lastFireTime;

	void fire(double elapsedTime);
	void move(Map& map, Player& player, double elapsedTime);

public:
	BossStage6Police(int x, int y, int direction);
	~BossStage6Police();

	int update(Map& map, double elapsedTime, Player& player);

	void death(Map& map);

};

