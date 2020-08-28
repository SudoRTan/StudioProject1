#include "BossStage3Virus.h"

BossStage3Virus::BossStage3Virus()
{
	position.setX(118);
	position.setY(2);
	setHealth(50);
	setDamage(20);
	updateDelay = 0.07;
	damageDelay = 0.3;
	cleanUp();
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
	mode = MOVING;
	moves = 0;
	completedAction = false;
}

BossStage3Virus::~BossStage3Virus()
{
	
}

int BossStage3Virus::update(Map& map, double g_dElapsedTime, Player& player)
{
	updateNewPosition(map, position.getX(), position.getY());
	if (contactPlayer(position.getX(), position.getY(), player) == true)
		player.takeDamage(getDamage());
	moves++;
	return 0;
}

void BossStage3Virus::move(Player player)
{
	completedAction = false;
	if (position.getY() - player.getPositionY() < 0)
	{
		position.setY(position.getY() + 1);
	}
	else if (position.getY() - player.getPositionY() > 0)
	{
		position.setY(position.getY() - 1);
	}
	else
	{
		completedAction = true;
	}
}

void BossStage3Virus::shoot()
{
	//shoot
}

void BossStage3Virus::charge()
{
	completedAction = false;
	if (direction == LEFT)
	{
		if (position.getX() != 2)
			position.setX(position.getX() - 1);
		else
		{
			direction = RIGHT;
			completedAction = true;
		}
	}
	if (direction == RIGHT)
	{
		if (position.getX() != 117)
			position.setX(position.getX() + 1);
		else
		{
			direction = LEFT;
			completedAction = true;
		}
	}
}