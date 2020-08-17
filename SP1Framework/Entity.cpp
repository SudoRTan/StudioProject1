#include "Entity.h"
#include <thread>
#include <chrono>

Entity::Entity() 
{
	position.setX(0);
	position.setY(0);
}

Entity::~Entity()
{

}

Position Entity::getPosition()
{
	return position;
}

void Entity::moveLeft()
{
	position.setX(position.getX() - 1);
}

void Entity::moveRight()
{
	position.setX(position.getX() + 1);
}

void Entity::jump(int jumpHeight)
{
	for (int i = 0; i < 2; i++)
	{
		position.setY(position.getY() + 1);
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
	}
}

void Entity::drop()
{

}

void Entity::drop(int platformX, int platformY)
{
	
}