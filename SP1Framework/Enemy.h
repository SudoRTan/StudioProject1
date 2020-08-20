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
	int direction;

	Position enemypos;

public:
	Enemy();
	Enemy(int x, int y);
	~Enemy();
	int patrol(Map& map, double g_dElapsedTime); // for enemies on land moving left and right
	
	void random(Map& map, double g_dElapsedTime);

	int PlayerContact(Position playerpos);
};

