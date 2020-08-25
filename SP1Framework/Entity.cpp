#include "Entity.h"
#include <thread>
#include <chrono>

Entity::Entity(): health{0}, damage{0}, canJump{0}, lastJumpTime{0}
{
	damage = 0;
	damageDelay = 0;
	height = 0;
	lastDamageTime = 0;
	lastMovementTime = 0;
	symbolArray = nullptr;
	updateDelay = 0;
	width = 0;

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


void Entity::updateNewPosition(Map& map, int newX, int newY) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			map.setDefaultItem(position.getX() + i, position.getY() + j);
		}
	}
	position.setX(newX);
	position.setY(newY);

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			map.setItem(newX + i, newY + j, symbolArray[j][i]);
		}
	}
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
		case PLATFORM:
		case FLOOR:
		case '=':
			onSolidFloor = true;
			break;

		case EMPTY:
		default:
			onSolidFloor = false;
			break;

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
		case FLOOR:
			onSolidGround = true;
			break;
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

void Entity::resetHealth() {
	health = maxHealth;
}

void Entity::cleanUp() {
	for (int i = 0; i < width; i++) {
		delete[] symbolArray[i];
	}

	delete[] symbolArray;
}