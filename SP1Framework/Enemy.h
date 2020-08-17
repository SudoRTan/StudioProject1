#pragma once
#include "Entity.h"
#include "Position.h"

class Enemy :
	public Entity
{
private:
	int damagetaken;
	Position enemypos;
public:
	Enemy();
	~Enemy();
	void Movement();
	int PlayerContact(Position playerpos);
};

