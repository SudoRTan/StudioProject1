#pragma once
#include "Enemy.h"
#include "Player.h"

enum VIRUS_MODE_ENUM {
	SHOOTING,
	MOVING, 
	CHARGING
};


class BossStage3Virus :
	public Enemy
{
public:
	BossStage3Virus();
	~BossStage3Virus();
	int update(Map& map, double g_dElapsedTime, Player& player);
private:
	int mode; //1 for shooting, 2 for moving, 3 for charging
	int directionMoving; //1 for up, 2 for down
	int directionFacing; //1 for facing left, 2 for facing right
	int newPositionX;
	int newPositionY;
};

