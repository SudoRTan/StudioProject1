#pragma once
#include "Entity.h"
#include "Position.h"
#include "Map.h"



class Enemy :
	public Entity
{
private:
	int damagetaken;

	Position enemypos;

public:
	Enemy();
	Enemy(int x, int y);
	~Enemy();
	int patrol(Map& map, double g_dElapsedTime); // for enemies on land moving left and right
	
	void random(Map& map, double g_dElapsedTime);

	virtual int update(Map& map, double g_dElapsedTime);


	int PlayerContact(Position playerpos);
};

Enemy* getEnemy(int x, int y, Enemy** enemy, int arraySize);

