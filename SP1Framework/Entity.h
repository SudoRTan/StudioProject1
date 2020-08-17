#pragma once
#include "Position.h"
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
	void moveLeft(); //to be virtual, add movement range ltr(can make zoom zoom enemy)
	void moveRight(); //to be virtual, add movement range ltr(can make zoom zoom enemy)
	void jump(int jumpHeight); //to be virtual
	void drop(); //to be virtual
	void setHealth(int newHealth);
	void setDamage(int newDamage);
};