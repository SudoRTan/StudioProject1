#include "BossStage6Police.h"

int BossStage6Police::numOfPoliceLeft = 0;

BossStage6Police::BossStage6Police(int x, int y, int direction) {
	cleanUp();

	state = POLICE_SHOOTING;

	position.setX(x);
	position.setY(y);
	this->direction = direction;

	futureY = position.getY();

	height = 3;
	width = 1;

	symbolArray = createArray(width, height);

	symbolArray[0][0] = 'A';
	symbolArray[1][0] = '|';

	switch (direction) {
	case LEFT:
		symbolArray[2][0] = '<';
		break;

	case RIGHT:
	default:
		symbolArray[2][0] = '>';
		break;
	}

	bullet = nullptr;

	lastFireTime = 0;

	// Each police have a unique firerate
	fireDelay = ((double)(rand() % 3) + 3) / 10;

	updateDelay = 0.1;
}

BossStage6Police::~BossStage6Police() {
	cleanUp();
	numOfPoliceLeft--;
}

int BossStage6Police::update(Map& map, double elapsedTime, Player& player) {



	switch (state){
	case POLICE_MOVING:
		move(map, player, elapsedTime);
		break;
	case POLICE_SHOOTING:
	default:
		fire(elapsedTime);
		break;
	}

	if (bullet != nullptr) {
		if (bullet->getHealth() == 0) {
			bullet->death(map);
			delete bullet;
			bullet = nullptr;
		}
		else {
			bullet->update(map, elapsedTime, &player);
		}
	}
	return 0;
}

void BossStage6Police::fire(double elapsedTime) {
	if (elapsedTime - lastFireTime > fireDelay) {
		int xOffSet = position.getX();
		switch (direction){
		case LEFT:
			xOffSet--;
			break;

		case RIGHT:
		default:
			xOffSet++;
			break;
		}


		if (bullet == nullptr) {
			bullet = new Projectile(xOffSet, position.getY() + 1, direction, 1, (char)254, 0.5);
			lastFireTime = elapsedTime;
			state = POLICE_MOVING;
			futureY =  1 + 3 * (rand() % 5);
		}
	}
}

void BossStage6Police::move(Map& map, Player& player, double elapsedTime)
{
	if (elapsedTime - lastMovementTime > updateDelay) {
		lastMovementTime = elapsedTime;
		int newX = position.getX();
		int newY = position.getY();

		// Check to see where the player is
		if (newY < futureY)
		{
			newY++;
		}
		else if (newY > futureY)
		{
			newY--;
		}
		else {
			state = POLICE_SHOOTING;
		}

		// Checks if the new location has space for the enemy to move into
		bool validMove = canEntityMove(map, newX, newY);


		if (validMove) {
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
		else {
			state = POLICE_SHOOTING;
		}
	}

}

void BossStage6Police::death(Map& map) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			map.setDefaultItem(position.getX() + i, position.getY() + j);
		}
	}
	if (bullet != nullptr) {
		bullet->death(map);
		delete bullet;
		bullet = nullptr;
	}

}

int BossStage6Police::getNumberOfPoliceLeft() {
	return numOfPoliceLeft;
}

void BossStage6Police::setMaxNumberOfPolice(int num) {
	numOfPoliceLeft = num;

}