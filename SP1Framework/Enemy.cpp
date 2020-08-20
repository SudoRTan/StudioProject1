#include "Enemy.h"


Enemy::Enemy()
{
	// test spawning of enemies on map using (5,4) as test case
	enemypos.setX(5);
	enemypos.setY(4);
	lastMovementTime = 0.00;
	updateDelay = 0.8;
	direction = 0;

}

Enemy::Enemy(int x, int y)
{
	position.setX(x);
	position.setY(y);

	lastMovementTime = 0.00;
	updateDelay = 0.3;
	direction = 0;
	setDamage(1);

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
		if (enemy[i]->getPositionX() == x && enemy[i]->getPositionY() == y) {
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
	