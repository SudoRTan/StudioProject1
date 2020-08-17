#pragma once
#include "Entity.h"
#include "Position.h"

class Enemy :
	public Entity
{
private:
	bool IsPlayerHit;
	Position enemypos;
public:
	Enemy();
	~Enemy();
	void Movement();
	void PlayerContact(Position playerpos);
};

