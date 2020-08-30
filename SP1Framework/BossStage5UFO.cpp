#include "BossStage5UFO.h"

BossStage5UFO::BossStage5UFO(int x, int y) {
	cleanUp();

	height = 2;
	width = 3;

	symbolArray = createArray(width, height);

	symbolArray[0][0] = '(';
	symbolArray[0][1] = '_';
	symbolArray[0][2] = ')';
	symbolArray[1][0] = ' ';
	symbolArray[1][1] = '^';
	symbolArray[1][2] = ' ';

	position.setX(x);

	position.setY(y);
	updateDelay = 0.05;

	damage = 4;
	health = 20;

}

BossStage5UFO::~BossStage5UFO() {

}

int BossStage5UFO::update(Map& map, double elapsedTime, Player& player) {
	
	switch (state) {
	case UFO_PANIC:
		break;

	case UFO_NORMAL:
	default:
		normalMove(map, elapsedTime, player);
		fire(elapsedTime);
		break;
	}
	return 0;
}


void BossStage5UFO::normalMove(Map& map, double elapsedTime, Player& player) {
	if (elapsedTime - lastMovementTime > updateDelay) {

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

		// if both bool functions return true, execute code to check if enemy collides with player.
		if (validMove) {
			// Resets the last movement time to current time
			lastMovementTime = elapsedTime;

			//Check if new location has a player
			if (contactPlayer(newX, newY, player)) {
				//Cause the player to take damamge if it contacts
				player.takeDamage(getDamage(), elapsedTime);
			}
			//Spot is empty and avaliable to move to 
			else {
				//Clear current map location and move to new location
				updateNewPosition(map, newX, newY);
			}
		}
		// if either of the bool function checks return false, reverse the direction that the enemy is facing
		else {
			direction = !direction;
		}
	}

}

void BossStage5UFO::fire(double elapsedTime) {

}