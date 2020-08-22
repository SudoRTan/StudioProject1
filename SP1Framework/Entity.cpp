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

void Entity::takeDamage(int damage) {
	health = health - damage;
}

bool Entity::isLocatedAt(int x, int y) {
	bool isPresent = false;

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			if (position.getX() + i == x && position.getY() + j == y) {
				isPresent = true;
			}
		}
	}
	return isPresent;
}

bool Entity::canEntityMove(Map& map, int x, int y) {
	bool validMove = false;
	
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			char itemAtNewLocation = map.getDefaultItem(x + i, y + j);
			switch (itemAtNewLocation) {
			case EMPTY:
			case PLATFORM:
				validMove = true;
				break;

			case INVALID:
			default:
				validMove = false;
				break;
			}
			if (validMove == false){
				return validMove;
			}
		}
	}
	return validMove;
}


bool Entity::onSolidFloor(Map& map, int x, int y) {
	bool onSolidFloor = true;
	for (int i = 0; i < width; i++) {
		char floorAtNewLocation = map.getDefaultItem(x + i, y - 1);
		switch (floorAtNewLocation) {
		case EMPTY:
			onSolidFloor = false;
			break;

		case PLATFORM:
		case '=':
			onSolidFloor = true;
		}
		if (onSolidFloor == false) {
			return onSolidFloor;
		}
	}
	return onSolidFloor;
}


bool Entity::hangingOnEdge(Map& map, int x, int y) {
	bool onEmptySpace = false;
	bool onSolidGround = false;
	for (int i = 0; i < width; i++) {
		char floorAtNewLocation = map.getDefaultItem(x + i, y - 1);
		
		switch (floorAtNewLocation) {
		case EMPTY:
			onEmptySpace = true;
			break;
		
		case PLATFORM:
		case '=':
			onSolidGround = true;
		}
	}
	if (onEmptySpace && onSolidGround) {
		return true;
	}
	else {
		return false;
	}
}



int Entity::getDirection() {
	return direction;
}