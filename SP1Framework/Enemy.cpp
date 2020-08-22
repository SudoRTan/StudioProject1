#include "Enemy.h"


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
}

Enemy::~Enemy()
{

}

int Enemy::patrol(Map& map, double g_dElapsedTime)
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
		else {
			direction = !direction;
		}




		/*
		char itemAtNewLocation = map.getItem(newX, newY);
		char floorAtNewLocation = map.getItem(newX, newY - 1);
		if (itemAtNewLocation == '9') {
			return PLAYER_DAMAGED;
		}
		else if (itemAtNewLocation != EMPTY || floorAtNewLocation == EMPTY){
			direction = !direction;
			return NO_CHANGE;
		}
		else {
			lastMovementTime = g_dElapsedTime;

			map.setDefaultItem(position.getX(), position.getY());

			position.setX(newX);
			position.setY(newY);

			map.setItem(position.getX(), position.getY(), 'E');
			return NO_CHANGE;
			*/
		
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


int Enemy::update(Map& map, double g_dElapsedTime) {
	return patrol(map, g_dElapsedTime);
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
		if (enemy[i]->isLocatedAt(x,y)) {
			returnEnemy = enemy[i];
		}
	}

	return returnEnemy;
}



// using setDamage function in Entity.h, setHealth(getHealth() - setDamage(PlayerContact()))
// set current health = initial health - set damage(return statement in Enemy::PlayerContact())

/*void Enemy::random(Map& map)
{
	int random = rand() % 5;
	switch (random)
	{
	case(1):
		{
		if (enemypos.getY() == 0)
			break;
		// if 
		else
			{
				for (int up = 0; up < 3; up++)
					enemypos.setY(enemypos.getY() + 1);
			}
			
		}
	case (2):
		{
			if (enemypos.getY() == 24)
				break;
			//
			else
			{
				for (int down = 0; down < 3; down++)
				{
					enemypos.setY(enemypos.getY() - 1);
				}
			}


		}
	case (3):
		{
			if (enemypos.getX() == 0)
				break;
			//
			else
			{
				for (int left = 0; left < 3; left++)
				{
					enemypos.setX(enemypos.getX() - 3);
				}
			}


		}
	case (4):
		{
			if (enemypos.getX() == 0 )
				break;
			//
			else
			{
				for (int right = 0; right < 3; right++)
				{
					enemypos.setX(enemypos.getX() + 3);
			    }
			}
		}


	}


}*/
	