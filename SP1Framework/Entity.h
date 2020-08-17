#pragma once
#include "Position.h"
class Entity
{
public:
	Entity();
	~Entity();
	Position getPosition();
	int getHealth();
	int getDamage();
protected:
	Position position;
	int health;
	int damage;
	void moveLeft();
	void moveRight();
	void jump(int jumpHeight);
	void drop();
	void setHealth(int newHealth);
	void setDamage(int newDamage);
};