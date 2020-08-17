#pragma once
#include "Position.h"
class Entity
{
public:
	Entity();
	~Entity();
protected:
	Position position;
	void moveLeft();
	void moveRight();
	void jump(int jumpHeight);
	void drop();
};