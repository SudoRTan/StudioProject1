#include "BossStage3Virus.h"

BossStage3Virus::BossStage3Virus() : projectileArray{nullptr,nullptr,nullptr}
{
	//Sets initial enemy health/locatiom/contact damage
	position.setX(77);
	position.setY(1);
	setHealth(20);
	setDamage(30);

	cleanUp();

	// Initilize symbol array
	height = 3;
	width = 3;
	symbolArray = createArray(width, height);
	symbolArray[0][0] = (char)197;
	symbolArray[0][1] = (char)194;
	symbolArray[0][2] = (char)197;
	symbolArray[1][0] = (char)180;
	symbolArray[1][1] = (char)35;
	symbolArray[1][2] = (char)195;
	symbolArray[2][0] = (char)197;
	symbolArray[2][1] = (char)193;
	symbolArray[2][2] = (char)197;

	//Initialze boss variables

	//Sets initial attack state
	mode = MOVING_LOOP;
	loopPart = 0;

	// future locations to move to 
	toX = 77;
	toY = 1;

	//Variables to track attack time
	shootDelay = 0.5;
	lastShootTime = 0;

	//Variables to track charge time
	chargeDelay = 0.3;
	lastChargeTime = 0;

	//Variables to track move time
	updateDelay = 0.5;
	lastMovementTime = 0;

}

BossStage3Virus::~BossStage3Virus()
{
	cleanUp();
}

int BossStage3Virus::update(Map& map, double elapsedTime, Player& player)
{
	switch (mode) {
	case SHOOT_LOOP:
		shoot(elapsedTime);
		break;

	case CHARGE_LOOP:
		charge(map, player, elapsedTime);
		break;

	case MOVING_LOOP:
		move(map, player, elapsedTime);
		break;

	default:
		break;
	}
	
	for (int i = 0; i < 3; i++) {
		if (projectileArray[i] != nullptr) {
			if (projectileArray[i]->getHealth() == 0) {
				projectileArray[i]->death(map);
				delete projectileArray[i];
				projectileArray[i] = nullptr;
			}
			else {
				projectileArray[i]->update(map, elapsedTime, &player);
			}
		}
	}

	return 0;
}

void BossStage3Virus::move(Map& map, Player& player, double elapsedTime)
{
	if (elapsedTime - lastMovementTime > updateDelay) {
		lastMovementTime = elapsedTime;
		int newX = position.getX();
		int newY = position.getY();

		// Check to see where the player is
		if (newY < toY)
		{
			newY++;
		}
		else if (newY > toY)
		{
			newY--;
		}
		else {
			mode = SHOOT_LOOP;
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
			mode = SHOOT_LOOP;
		}
	}

}

void BossStage3Virus::shoot(double elapsedTime){

	if (elapsedTime - lastShootTime > shootDelay) {
		lastShootTime = elapsedTime;

		int i = 0;
		//Loop through everything in the projectileArray array until it finds a nullptr
		while (i < 3) {
			if (projectileArray[i] == nullptr) {
				// Spawn projectile based on direction facing
				switch (direction) {
				case LEFT:
					projectileArray[i] = new Projectile(position.getX() - 1, position.getY() + 1, direction, 5, (char)254, 0.5);
					break;

				case RIGHT:
					projectileArray[0] = new Projectile(position.getX() + 3, position.getY() + 1, direction, 5, (char)254, 0.5);
					break;

				default:
					break;
				}
				// Move to a new Y location
				lastShootTime = elapsedTime;
				toY = 1 + 3 * (rand() % 5);
				loopPart++;

				mode = MOVING_LOOP;
				break;
			}
			i++;
		}
		// If its the third time shooting
		if (loopPart == 3) {
			// Based on direction move to new X coordinate
			switch(direction) {
			case LEFT:
				toX = 0;
				break;

			case RIGHT:
				toX = 77;
				break;

			default:
				break;
			}
			mode = CHARGE_LOOP;
			loopPart = 0;
		}
	}

}

void BossStage3Virus::charge(Map& map, Player& player, double elapsedTime)
{
	if (elapsedTime - lastChargeTime > chargeDelay) {
		lastMovementTime = elapsedTime;
		int newX = position.getX();
		int newY = position.getY();

		// Check to see where the player is
		if (newX < toX)
		{
			newX++;
		}
		else if (newX > toX)
		{
			newX--;
		}
		else {
			// Inverse direction and set stage back to shooting
			direction = !direction;
			mode = SHOOT_LOOP;
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
			// Inverse direction and set stage back to shooting
			direction = !direction;
			mode = SHOOT_LOOP;
		}
	}
	
}