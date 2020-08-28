#pragma once
#include "Enemy.h"
#include "Player.h"
#include "Projectile.h"

enum VIRUS_MODE_ENUM
{
	SHOOTING,
	MOVING, 
	CHARGING
};

enum MOVEMENT_CASE
{
	SHOOT_LOOP,
	CHARGE_LOOP
};

class BossStage3Virus :
	public Enemy
{
public:
	BossStage3Virus();
	~BossStage3Virus();
	int update(Map& map, double g_dElapsedTime, Player& player);
private:
	int mode;
	int caseLoop;
	int shootLoopCount;
	double lastShootTime;
	bool completedAction;
	Projectile* projectileArray[3];
	void move(Player player);
	void shoot(double g_dElapsedTime);
	void charge();
};

