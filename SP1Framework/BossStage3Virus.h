#pragma once
#include "Enemy.h"
#include "Player.h"
#include "Projectile.h"

enum VIRUS_MODE_ENUM
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
	int loopPart;
	int toX;
	int toY;
	double lastShootTime;
	Projectile* projectileArray[3];
	void move(Map map);
	void shoot(double g_dElapsedTime);
	void charge(Map map);
};

