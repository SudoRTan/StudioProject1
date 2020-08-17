#pragma once
#include "Entity.h"
//#include "Position.h"

class Enemy :
	public Entity
{
private:
	//Position pos;
public:
	Enemy();
	~Enemy();
	void Movement();
};

