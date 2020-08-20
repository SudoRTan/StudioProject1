#pragma once
#include "Position.h"
#include "Map.h"


enum ENTITY_STATE {
	NO_CHANGE,
	PLAYER_DAMAGED
	
};


enum DIRECTION {
	LEFT,
	RIGHT
};

class Entity
{

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

	int direction;

	void setHealth(int newHealth);
	void setDamage(int newDamage);

public:
	Entity();
	~Entity();
	int getPositionX();
	int getPositionY();
	int getHealth();
	int getDamage();

	void takeDamage(int damage, double g_dElapsedTime);

	void takeDamage(int damage);


	int getDirection();

};