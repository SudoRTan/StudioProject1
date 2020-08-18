#include "Entity.h"
#include <thread>
#include <chrono>

Entity::Entity(): health{0}, damage{0}, jumpHeight{0}, lastJumpTime{0}
{
	position.setX(0);
	position.setY(0);
}

Entity::~Entity()
{

}

int Entity::getPositionX()
{
	return position.getX();
}

int Entity::getPositionY()
{
	return position.getY();
}

int Entity::getHealth()
{
	return health;
}

int Entity::getDamage()
{
	return damage;
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
	}
}

void Entity::drop()
{
	position.setY(position.getY() - 1);
}

void Entity::setHealth(int newHealth)
{
	health = newHealth;
}

void Entity::setDamage(int newDamage)
{
	damage = newDamage;
}