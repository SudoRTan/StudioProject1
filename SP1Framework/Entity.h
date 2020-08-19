#pragma once
#include "Position.h"
#include "Map.h"


class Entity
{
public:
	Entity();
	~Entity();
	int getPositionX();
	int getPositionY();
	int getHealth();
	int getDamage();

protected:
	Position position;
	int health;
	int damage;
	int canJump;
	double lastJumpTime;
	double lastMovementTime;
	double updateDelay;

	void setHealth(int newHealth);
	void setDamage(int newDamage);
};