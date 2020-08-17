#include "Entity.h"

Entity::Entity() 
{

}

Entity::~Entity()
{

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
	
}

void Entity::drop()
{
	
}