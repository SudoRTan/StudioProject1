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

public:
	Enemy();
	Enemy(int x, int y);
	~Enemy();
	void PatrolMovement(); // for enemies on land moving left and right
	//void RandMovement(); // for flying enemies moving up and down
	
	
	void random(Map& map, double g_dElapsedTime);

	int PlayerContact(Position playerpos);
};

