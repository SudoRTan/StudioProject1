#include "Enemy.h"
#include "Player.h"


Enemy::Enemy()
{
	// test spawning of enemies on map using (5,4) as test case
	// default constructor will create an enemy of 2x2 size with 2 health.
	// this block of code is called if the symbol on the text file is an 'E'.
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
	//overload default constructor to pass in x and y values to precisely place position of enemy at specific positions on map
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
	cleanUp();
}

int Enemy::patrol(Map& map, double g_dElapsedTime, Player& player)
{
	if (g_dElapsedTime - lastMovementTime > updateDelay) {
		lastJumpTime = g_dElapsedTime;

		int newX = position.getX();
		int newY = position.getY();

		// have enemy continually move in 1 direction until unable to
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
		// Checks if the new location has space for the enemy to move into
		bool validMove = canEntityMove(map, newX, newY);
		
		// Checks if the new location has a solid floor / platform for the player to stand on
		bool solidFloor = onSolidFloor(map, newX, newY);

		// if both bool functions return true, execute code to check if enemy collides with player.
		if (validMove && solidFloor) {
			// Resets the last movement time to current time
			lastMovementTime = g_dElapsedTime;
			
			//Check if new location has a player
			if (contactPlayer(newX, newY, player)) {
				//Cause the player to take damamge if it contacts
				player.takeDamage(getDamage(), g_dElapsedTime);
			}
			//Spot is empty and avaliable to move to 
			else{
				//Clear current map location and move to new location
				updateNewPosition(map, newX, newY);
			}
		}
		// if either of the bool function checks return false, reverse the direction that the enemy is facing
		else {
			direction = !direction;
		}
	}
	return NO_CHANGE;
}

void Enemy::random(Map& map, double g_dElapsedTime, Player& player)
{
	// same code as patrol movement above
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

		// Checks if the new location has space for the enemy to move into
		bool validMove = canEntityMove(map, newX, newY);

		// Checks if the new location has a solid floor / platform for the player to stand on
		bool solidFloor = onSolidFloor(map, newX, newY);

		// if both bool functions return true, execute code to check if enemy collides with player.
		if (validMove && solidFloor) {
			// Resets the last movement time to current time
			lastMovementTime = g_dElapsedTime;

			//Check if new location has a player
			if (contactPlayer(newX, newY, player)) {
				//Cause the player to take damamge if it contacts
				player.takeDamage(getDamage(), g_dElapsedTime);
			}
			//Spot is empty and avaliable to move to 
			else {
				//Clear current map location and move to new location
				updateNewPosition(map, newX, newY);
			}
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



Enemy* getEnemy(int x, int y, Enemy** enemy, int arraySize) {
	Enemy* returnEnemy = nullptr;

	if (enemy != nullptr) {
		for (int i = 0; i < arraySize; i++) {
			if (enemy[i] != nullptr) {
				if (enemy[i]->isLocatedAt(x, y)) {
					returnEnemy = enemy[i];
				}
			}
		}
	}
	

	return returnEnemy;
}

