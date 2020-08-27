#pragma once
#include "Player.h"
#include "Enemy.h"
class BossStage1Fire :
	public Enemy
{
public:
	BossStage1Fire(int x, int y);
	~BossStage1Fire();
	int update(Map& map, double g_dElapsedTime, Player& player);
	bool getCanSpawnLeft();
	bool getCanSpawnRight();
	void updateSpawnBool(Map* map);
private:
	bool canSpawnLeft;
	bool canSpawnRight;
	void setCanSpawnLeft(bool newBool);
	void setCanSpawnRight(bool newBool);
};