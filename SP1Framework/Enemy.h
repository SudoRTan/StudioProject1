#pragma once
#include "Entity.h"
#include "Position.h"
#include "Map.h"
#include "ctime"


class Enemy :
	public Entity
{
private:
	int damagetaken;
	Position enemypos;
	void patrol(Map& map, double g_dElapsedTime);
void random(Map& map);

public:
	Enemy();
	Enemy(int x, int y);
	~Enemy();
	void PatrolMovement(); // for enemies on land moving left and right
	void RandMovement(); // for flying enemies moving up and down
	int PlayerContact(Position playerpos);
};

