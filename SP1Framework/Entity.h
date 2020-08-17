#pragma once
#include "Position.h"
class Entity
{
public:
	Entity();
	~Entity();
	Position getPosition();
protected:
	Position position;
	void moveLeft();
	void moveRight();
	void jump(int jumpHeight);
	void drop();
	void drop(int platformX, int platformY);
};