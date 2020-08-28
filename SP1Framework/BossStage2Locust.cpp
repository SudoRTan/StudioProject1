#include "BossStage2Locust.h"

BossStage2Locust:: BossStage2Locust()
{
	position.setX(rand() % 120);
	position.setY(1 + 3 * (rand() % 5));
	health = 2;
	updateDelay = 0.1;
	setDamage(10);
	direction = rand() % 2;

	currentState = LOCUST_WAITING;

	timeStartedWaiting = 0;

	futureX = position.getX();
	futureY = position.getY();

}

BossStage2Locust::~BossStage2Locust()
{

}


int BossStage2Locust::update(Map& map, double g_dElapsedTime, Player& player) {
	if (g_dElapsedTime - lastMovementTime > updateDelay) {
		lastMovementTime = g_dElapsedTime;

		if (currentState == LOCUST_MOVING) {
			
			int newX = position.getX();
			int newY = position.getY();
			if (newX == futureX && newY == futureY) {
				currentState = LOCUST_WAITING;
				timeStartedWaiting = g_dElapsedTime;
			}
			else {
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
				if (canEntityMove(map, newX, newY)) {
					updateNewPosition(map, newX, newY);
				}
				else {
					currentState = LOCUST_WAITING;
					timeStartedWaiting = g_dElapsedTime;
				}
			}
		}
		else if (currentState == LOCUST_WAITING){
			if (g_dElapsedTime - timeStartedWaiting > 5) {
				currentState = LOCUST_MOVING;
				switch (rand() % 2) {
				case 0:
					futureX = rand() % 120;
					break;

				case 1:
				default:
					futureY = 1 + 3 * (rand() % 5);
					break;
				}
			}
		}
	}
	
	
	
	//patrol(map, g_dElapsedTime, player);
	return 0;
}

/*
void BossStage2Locust::death(Map& map) {


}
*/