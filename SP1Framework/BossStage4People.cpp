#include "BossStage4People.h"



BossStage4People::BossStage4People(int type) : Enemy()
{
	updateDelay = 3;
	cleanUp();
	personType = type;

	switch (type)
	{
	case GUNMAN:
		position.setX(0);
		position.setY(1);
		height = 3;
		width = 2;
		symbolArray = createArray(width, height);
		symbolArray[0][0] = (char)65;
		symbolArray[0][1] = (char)32;
		symbolArray[1][0] = (char)124;
		symbolArray[1][1] = (char)169;
		symbolArray[2][0] = (char)79;
		symbolArray[2][1] = (char)32;
		break;

	case KNIFEMAN:
		position.setX(77);
		position.setY(1);
		setDamage(10);
		height = 3;
		width = 3;
		symbolArray = createArray(width, height);
		symbolArray[0][0] = (char)32;
		symbolArray[0][1] = (char)32;
		symbolArray[0][2] = (char)65;
		symbolArray[1][0] = (char)45;
		symbolArray[1][1] = (char)198;
		symbolArray[1][2] = (char)180;
		symbolArray[2][0] = (char)32;
		symbolArray[2][1] = (char)32;
		symbolArray[2][2] = (char)79;
		break;
	}
	projectile = nullptr;
}

BossStage4People::~BossStage4People()
{
	cleanUp();
}

int BossStage4People::update(Map& map, double g_dElapsedTime, Player& player)
{
	updateNewPosition(map, position.getX(), position.getY());
	if (personType == GUNMAN)
	{
		if (g_dElapsedTime - lastMovementTime > 2){
			lastMovementTime = g_dElapsedTime;
			if (projectile == nullptr) {
				projectile = new Projectile(position.getX(), position.getY(), RIGHT, 5, (char)254, 4);

			}
		}
		if (projectile != nullptr) {
			projectile->update(map, g_dElapsedTime, &player);
			if (projectile->getHealth() == 0) {
				projectile->death(map);
				delete projectile;
				projectile = nullptr;
			}

		}

	}
	else if (personType == KNIFEMAN)
	{
		int newX = position.getX() - 1;
		int newY = position.getY();


		bool validMove = canEntityMove(map, newX, newY);

		if (validMove) {
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
	return NO_CHANGE;
}