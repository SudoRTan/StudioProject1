#pragma once
#include "Entity.h"
#include "Position.h"
#include "Map.h"

class Player;

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
	int patrol(Map& map, double g_dElapsedTime, Player& player); // for enemies on land moving left and right
	
	void random(Map& map, double g_dElapsedTime);

	virtual int update(Map& map, double g_dElapsedTime, Player& player);

	bool contactPlayer(int x, int y, Player& player);

	int PlayerContact(Position playerpos);
};

Enemy* getEnemy(int x, int y, Enemy** enemy, int arraySize);

