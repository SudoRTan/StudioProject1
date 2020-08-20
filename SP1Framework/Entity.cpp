#include "Entity.h"
#include <thread>
#include <chrono>

Entity::Entity(): health{0}, damage{0}, canJump{0}, lastJumpTime{0}
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

void Entity::setHealth(int newHealth)
{
	health = newHealth;
}

void Entity::setDamage(int newDamage)
{
	damage = newDamage;
}

void Entity::takeDamage(int damage, double g_dElapsedTime) {
	if (g_dElapsedTime - lastDamageTime > damageDelay) {
		health = health - damage;
		lastDamageTime = g_dElapsedTime;
	}
}