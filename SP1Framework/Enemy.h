#pragma once
#include "Entity.h"
#include "Position.h"

class Enemy :
	public Entity
{
private:
	Position enemypos;
public:
	Enemy();
	~Enemy();
	void Movement();
};

