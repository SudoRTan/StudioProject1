#pragma once
#include "Enemy.h"
#include "Player.h"
#include "Projectile.h"

enum VIRUS_MODE_ENUM
{
	MOVING_LOOP,
	SHOOT_LOOP,
	CHARGE_LOOP
};

class BossStage3Virus :
	public Enemy
{
public:
	BossStage3Virus();
	~BossStage3Virus();
	int update(Map& map, double elapsedTime, Player& player);


private:
	int mode;
	int loopPart;
	int toX;
	int toY;
	
	
	double shootDelay;
	double lastShootTime;
	
	double chargeDelay;
	double lastChargeTime;



	Projectile* projectileArray[3];
	
	
	void move(Map& map, Player& player, double elapsedTime);
	void shoot(double elapsedTime);
	void charge(Map& map, Player& player, double elapsedTime);

};

