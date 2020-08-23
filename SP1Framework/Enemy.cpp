#include "Enemy.h"
#include "Player.h"


Enemy::Enemy()
{
	// test spawning of enemies on map using (5,4) as test case
	enemypos.setX(5);
	enemypos.setY(4);
	lastMovementTime = 0.00;
	updateDelay = 0.8;
	direction = 0;

	height = 2;
	width = 2;

	symbolArray = createArray(width, height);
	
	symbolArray[0][0] = 'E';
	symbolArray[1][0] = 'E';
	symbolArray[0][1] = 'E';
	symbolArray[1][1] = 'E';

	setHealth(2);
}

Enemy::Enemy(int x, int y)
{
	position.setX(x);
	position.setY(y);

	lastMovementTime = 0.00;
	updateDelay = 0.3;
	direction = 0;
	setDamage(1);

	height = 2;
	width = 2;

	symbolArray = createArray(width, height);

	symbolArray[0][0] = 'E';
	symbolArray[1][0] = 'E';
	symbolArray[0][1] = 'E';
	symbolArray[1][1] = 'E';

	setHealth(2);

}

Enemy::~Enemy()
{

}

int Enemy::patrol(Map& map, double g_dElapsedTime, Player& player)
{
	if (g_dElapsedTime - lastMovementTime > updateDelay) {
		lastJumpTime = g_dElapsedTime;

		int newX = position.getX();
		int newY = position.getY();

		switch (direction) {
		case 0:
			newX--;
			break;

		case 1:
			newX++;
			break;

		default:
			break;
		}

		bool validMove = canEntityMove(map, newX, newY);
		bool solidFloor = onSolidFloor(map, newX, newY);
		if (validMove && solidFloor) {
			lastMovementTime = g_dElapsedTime;
			if (contactPlayer(newX, newY, player)) {
				player.takeDamage(getDamage(), g_dElapsedTime);
			}
			else{
				updateNewPosition(map, newX, newY);
			}
		}
		else {
			direction = !direction;
		}
	}
	return NO_CHANGE;
}

void Enemy::random(Map& map, double g_dElapsedTime)
{
	if (g_dElapsedTime - lastMovementTime > updateDelay) {
		lastJumpTime = g_dElapsedTime;

		int newX = position.getX();
		int newY = position.getY();

		switch (rand() % 2) {
		case 0:
			newX--;
			break;

		case 1:
			newX++;
			break;

		default:
			break;
		}

		if (map.getItem(newX, newY) == EMPTY) {
			lastMovementTime = g_dElapsedTime;

			map.setDefaultItem(position.getX(), position.getY());

			position.setX(newX);
			position.setY(newY);

			map.setItem(position.getX(), position.getY(), 'E');
		}
	}

}


int Enemy::update(Map& map, double g_dElapsedTime, Player& player) {
	return patrol(map, g_dElapsedTime, player);
}

void Enemy::death(Map& map) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			map.setDefaultItem(position.getX() + i, position.getY() + j);
		}
	}
}

bool Enemy::contactPlayer(int x, int y, Player& player) {
	bool contactingPlayer = false;
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			if (player.isLocatedAt(x + i, y + j)) {
				contactingPlayer = true;
			}
			 
		}
	}
	return contactingPlayer;
}


int Enemy::PlayerContact(Position playerpos) // pass in player's position object into playerpos
{
	if ((playerpos.getX() == enemypos.getX()) && (playerpos.getY() == enemypos.getY())) // check if player into enemy
	{
		damagetaken = 2;
		// reduce health by some amount
	}
	return damagetaken;
}


Enemy* getEnemy(int x, int y, Enemy** enemy, int arraySize) {
	Enemy* returnEnemy = nullptr;

	for (int i = 0; i < arraySize; i++) {
		if (enemy[i] != nullptr) {
			if (enemy[i]->isLocatedAt(x, y)) {
				returnEnemy = enemy[i];
			}
		}
	}

	return returnEnemy;
}

