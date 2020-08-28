#include "Projectile.h"
#include "Player.h"

Projectile::Projectile(int x, int y, int direction) {
	position.setX(x);
	position.setY(y);

	height = 1;
	width = 1;
	symbolArray = createArray(height, width);

	symbolArray[0][0] = '*';

	this->direction = direction;
	updateDelay = 0.5;
	health = 1;

	damage = 2;

}

	
Projectile::Projectile(int x, int y, int direction, int damage) :Projectile(x, y, direction) {
	this->damage = damage;
}


Projectile::Projectile(int x, int y, int direction, int damage, char projectileSymbol, double speed) :Projectile(x, y, direction) {
	this->damage = damage;
	symbolArray[0][0] = projectileSymbol;
	updateDelay = speed;

}



Projectile::~Projectile() {
	cleanUp();

}

void Projectile::update(Map& map, double elapsedTime, Player* player) {
	if (elapsedTime - lastMovementTime > updateDelay) {
		int newX = position.getX();
		int newY = position.getY();
		
		switch (direction) {
		case LEFT:
			newX--;
			break;

		case RIGHT:
			newX++;
			break;

		case UP:
			newY++;
			break;

		case DOWN:
			newY--;
			break;

		default:
			break;
		}
		if (player->isLocatedAt(newX, newY)) {
			player->takeDamage(damage);
			health = 0;
		}

		else if (canEntityMove(map, newX, newY)) {
			updateNewPosition(map, newX, newY);
		}
		else {
			map.setDefaultItem(position.getX(), position.getY());
			health = 0;
		}
	}
}

void Projectile::update(Map& map, double elapsedTime, Enemy** enemyArray, int enemyArraySize) {
	if (elapsedTime - lastMovementTime > updateDelay) {
		int newX = position.getX();
		int newY = position.getY();

		switch (direction) {
		case LEFT:
			newX--;
			break;

		case RIGHT:
			newX++;
			break;

		case UP:
			newY++;
			break;

		case DOWN:
			newY--;
			break;

		default:
			break;
		}

		Enemy* enemyAtNewLocation = getEnemy(newX, newY, enemyArray, enemyArraySize);

		if (enemyAtNewLocation != nullptr) {
			enemyAtNewLocation->takeDamage(damage);
			health = 0;
		}
		else if (canEntityMove(map, newX, newY)) {
			updateNewPosition(map, newX, newY);
		}
		else {
			map.setDefaultItem(position.getX(), position.getY());
			health = 0;
		}
	}
}