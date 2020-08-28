#pragma once
#include "Enemy.h"
#include "Player.h"
#include "Projectile.h"

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
	int mode;
	int moves;
	bool completedAction;
	void move(Player player);
	void shoot();
	void charge();
};

