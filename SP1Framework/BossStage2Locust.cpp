#include "BossStage2Locust.h"


int BossStage2Locust::numberOfLocusts = 0;

BossStage2Locust::BossStage2Locust(int x, int y) : Enemy(x, y)
{
	health = 2;
	updateDelay = 0.01;
	setDamage(1);
	

 	currentState = LOCUST_WAITING;

	timeStartedWaiting = 0;

	futureX = position.getX();
	futureY = position.getY();

	//cleanUp();
	height = 1;
	width = 1;
	symbolArray = createArray(width, height);
	symbolArray[0][0] = (char)236;

	numberOfLocusts++;
}

BossStage2Locust::~BossStage2Locust()
{	numberOfLocusts--;
}


int BossStage2Locust::update(Map& map, double elapsedTime, Player& player) {
	if (elapsedTime - lastMovementTime > updateDelay) {
		lastMovementTime = elapsedTime;
		switch (currentState) {
		case LOCUST_MOVING:
			move(map, elapsedTime, player);
			break;

		case LOCUST_WAITING:
			wait(elapsedTime);
			break;

		default:
			break;
		}
	}
	return 0;
}

int BossStage2Locust::getNumberOfLocusts()
{
	return numberOfLocusts;
}


void BossStage2Locust::move(Map& map, double elapsedTime, Player& player) {

	int newX = position.getX();
	int newY = position.getY();
	
	if (newX > futureX) {
		newX--;
	}
	else if (newX < futureX) {
		newX++;
	}

	if (newY > futureY) {
		newY--;
	}
	else if (newY < futureY) {
		newY++;
	}


	if (newX == futureX && newY == futureY) {
		currentState = LOCUST_WAITING;
		timeStartedWaiting = elapsedTime;
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
		currentState = LOCUST_WAITING;
		timeStartedWaiting = elapsedTime;
	}

}

void BossStage2Locust::wait(double elapsedTime) {
	if (elapsedTime - timeStartedWaiting > 1) {
		currentState = LOCUST_MOVING;
		switch (rand() % 2) {
		case 0:
			futureX = rand() % 120;
			break;

		case 1:
		default:
			futureY = 2 + 3 * (rand() % 5);
			break;
		}
	}
}