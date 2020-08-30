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
	
	updateDelay = 0.1;

	panicStartTime = 0;
	panicDelay = 0.05;

	panicDuration = 5;

	damage = 4;
	health = 20;
	previousHealth = 20;

	numberOfBullets = 3;
	bullets = new Projectile*[numberOfBullets];

	for (int i = 0; i < numberOfBullets; i++) {
		bullets[i] = nullptr;
	}

	lastFireTime = 0;
	fireDelay = 0.5;

	state = UFO_NORMAL;
}

BossStage5UFO::~BossStage5UFO() {
	for (int i = 0; i < numberOfBullets; i++) {
		if (bullets[i] != nullptr) {
			delete bullets[i];
			bullets[i] = nullptr;
			
		}
	}
	delete[] bullets;

	cleanUp();
}

int BossStage5UFO::update(Map& map, double elapsedTime, Player& player) {
	if (previousHealth != health) {
		previousHealth = health;
		state = UFO_PANIC;
		panicStartTime = elapsedTime;
	}
	else if (elapsedTime - panicStartTime > panicDuration) {
		state = UFO_NORMAL;
	}

	switch (state) {
	case UFO_PANIC:
		panicMove(map, elapsedTime, player);
		fire(elapsedTime, true);
		break;

	case UFO_NORMAL:
	default:
		normalMove(map, elapsedTime, player);
		fire(elapsedTime, false);
		break;
	}

	//Updates Bullets
	for (int i = 0; i < numberOfBullets; i++) {
		if (bullets[i] != nullptr) {
			if (bullets[i]->getHealth() == 0) {
				bullets[i]->death(map);
				delete bullets[i];
				bullets[i] = nullptr;
			}
			else {
				bullets[i]->update(map, elapsedTime, &player);
			}
		}
	}

	return 0;
}

void BossStage5UFO::panicMove(Map& map, double elapsedTime, Player& player) {
	if (elapsedTime - lastMovementTime > panicDelay) {

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

void BossStage5UFO::fire(double elapsedTime, bool panic) {
	if (elapsedTime - lastFireTime > fireDelay) {
		lastFireTime = elapsedTime;

		// Randomize fire time
		if (panic) {
			fireDelay = ((double)(rand() % 3) + 1.0) / 10;
		}
		else {
			fireDelay = ((double)(rand() % 6) + 1.0) / 10;
		}

		int i = 0;
		//Loop through everything in the bullets array until it finds a nullptr
		while (i < numberOfBullets) {
			if (bullets[i] == nullptr) {
				bullets[i] = new Projectile(position.getX() + 1, position.getY(), DOWN, 5, (char)254, 0.5);
				lastFireTime = elapsedTime;
				break;
			}
			i++;
		}
	}
}