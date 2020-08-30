#include "BossStage5UFO.h"

BossStage5UFO::BossStage5UFO()
{
	cleanUp();

	height = 2;
	width = 3;

	symbolArray = createArray(width, height);

	symbolArray[0][0] = (char)60;
	symbolArray[0][1] = (char)61;
	symbolArray[0][2] = (char)62;
	symbolArray[1][0] = (char)32;
	symbolArray[1][1] = (char)239;
	symbolArray[1][2] = (char)32;

	position.setX(77);
	position.setY(15);
	
	direction = DOWN;
	toY = 15;
	updateDelay = 0.1;
	damage = 4;
	health = 20;
	lastFireTime = 0;
}

BossStage5UFO::~BossStage5UFO()
{
	cleanUp();
	for (int i = 0; i < projectile.size(); i++)
	{
		delete projectile.at(i);
		projectile.at(i) = nullptr;
	}
}

int BossStage5UFO::update(Map& map, double elapsedTime, Player& player)
{
	//update ufo on map
	updateNewPosition(map, position.getX(), position.getY());

	//set new y to move to
	if (position.getY() == toY)
	{
		if (direction == UP)
		{
			toY = position.getY() - 5 - (rand() % 7);
			if (toY < 1)
				toY = 1;
			direction = DOWN;
		}
		else if (direction == DOWN)
		{
			toY = position.getY() + 5 + (rand() % 7);
			if (toY > 15)
				toY = 15;
			direction = UP;
		}
	}

	//move to new y
	if (elapsedTime - lastMovementTime > updateDelay)
	{
		if (position.getY() > toY)
			position.setY(position.getY() - 1);
		else if (position.getY() < toY)
			position.setY(position.getY() + 1);
		lastMovementTime = elapsedTime;
	}

	return NO_CHANGE;
}