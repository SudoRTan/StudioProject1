#pragma once
#include "Entity.h"
#include "Position.h"

class Enemy :
	public Entity
{
private:
	int damagetaken;
	Position enemypos;
	void patrol();
void random();

public:
	Enemy();
	~Enemy();
	void LRMovement(); // for enemies on land moving left and right
	void UDMovement(); // for flying enemies moving up and down
	int PlayerContact(Position playerpos);
};

