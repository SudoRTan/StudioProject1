#pragma once
#include "Position.h"
#include "Map.h"


enum ENTITY_STATE {
	NO_CHANGE,
	PLAYER_DAMAGED
	
};


class Entity
{
public:
	Entity();
	~Entity();
	int getPositionX();
	int getPositionY();
	int getHealth();
	int getDamage();

	void takeDamage(int damage, double g_dElapsedTime);

protected:
	Position position;
	int health;
	int damage;
	int canJump;


	double lastJumpTime;
	double lastMovementTime;
	double updateDelay;

	double damageDelay;
	double lastDamageTime;


	void setHealth(int newHealth);
	void setDamage(int newDamage);
};