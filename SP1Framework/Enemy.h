#pragma once
#include "Entity.h"
#include "Position.h"
#include "Map.h"

class Player;

class Enemy :
	public Entity
{
private:

public:
	Enemy();
	Enemy(int x, int y);
	virtual ~Enemy();
	int patrol(Map& map, double g_dElapsedTime, Player& player); // for enemies on land moving left and right
	
	void random(Map& map, double g_dElapsedTime);

	virtual int update(Map& map, double g_dElapsedTime, Player& player);

	void death(Map& map);

	bool contactPlayer(int x, int y, Player& player);

};

Enemy* getEnemy(int x, int y, Enemy** enemy, int arraySize);
