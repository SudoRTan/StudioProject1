#include "BossStage3Virus.h"

BossStage3Virus::BossStage3Virus() : projectileArray{nullptr}
{
	position.setX(67);
	position.setY(1);
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
	mode = SHOOT_LOOP;
	loopPart = 0;
	toX = 67;
	toY = 1;
	lastShootTime = 0;
}

BossStage3Virus::~BossStage3Virus()
{
	cleanUp();
}

int BossStage3Virus::update(Map& map, double g_dElapsedTime, Player& player)
{
	for (int i = 0; i < 3; i++)
		if (projectileArray[i] != nullptr)
			if (player.isLocatedAt(projectileArray[i]->getPositionX(), projectileArray[i]->getPositionY()))
				player.takeDamage(projectileArray[i]->getDamage());

	if (contactPlayer(position.getX(), position.getY(), player) == true)
		player.takeDamage(getDamage());

	if (mode == SHOOT_LOOP)
	{
		switch (loopPart)
		{
		case 0:
			toY = 1 + 3 * (rand() % 5);
			break;
		case 1:
		case 3:
		case 5:
			move(map);
			break;
		case 2:
		case 4:
		case 6:
			shoot(g_dElapsedTime);
			break;
		}
		if (loopPart == 6)
		{
			loopPart = 0;
			mode = CHARGE_LOOP;
		}
	}
	else if (mode == CHARGE_LOOP)
	{
		switch (loopPart)
		{
		case 0:
			switch (position.getX())
			{
			case 0:
				toX = 67;
				break;
			case 67:
				toX = 0;
				break;
			}
			toY = 1 + 3 * (rand() % 5);
			break;
		case 1:
			move(map);
			break;
		case 2:
			charge(map);
			break;
		}
		if (loopPart == 2)
		{
			loopPart = 0;
			mode = SHOOT_LOOP;
			updateDelay = 0.07;
		}
	}
	return NO_CHANGE;
}

void BossStage3Virus::move(Map map)
{
	if (position.getY() < toY)
	{
		updateNewPosition(map, position.getX(), position.getY() + 1);
	}
	else if (position.getY() > toY)
	{
		updateNewPosition(map, position.getX(), position.getY() - 1);
	}
	else
	{
		loopPart++;
	}
}

void BossStage3Virus::shoot(double g_dElapsedTime)
{
	if (g_dElapsedTime - lastShootTime > 0.5)
		if (projectileArray[0] == nullptr)
		{
			if (direction == LEFT)
			{
				projectileArray[0] = new Projectile(position.getX() - 1, position.getY() + 1, direction, 5, (char)254, 0.5);
				lastShootTime = g_dElapsedTime;
				loopPart++;
			}
			else
			{
				projectileArray[0] = new Projectile(position.getX() + 3, position.getY() + 1, direction, 5, (char)254, 0.5);
				lastShootTime = g_dElapsedTime;
				loopPart++;
			}
		}
		else if (projectileArray[1] == nullptr)
		{
			if (direction == LEFT)
			{
				projectileArray[1] = new Projectile(position.getX() - 1, position.getY() + 1, direction, 5, (char)254, 0.5);
				lastShootTime = g_dElapsedTime;
				loopPart++;
			}
			else
			{
				projectileArray[1] = new Projectile(position.getX() + 3, position.getY() + 1, direction, 5, (char)254, 0.5);
				lastShootTime = g_dElapsedTime;
				loopPart++;
			}
		}
		else if (projectileArray[2] == nullptr)
		{
			if (direction == LEFT)
			{
				projectileArray[2] = new Projectile(position.getX() - 1, position.getY() + 1, direction, 5, (char)254, 0.5);
				lastShootTime = g_dElapsedTime;
				loopPart++;
			}
			else
			{
				projectileArray[2] = new Projectile(position.getX() + 3, position.getY() + 1, direction, 5, (char)254, 0.5);
				lastShootTime = g_dElapsedTime;
				loopPart++;
			}
		}
}

void BossStage3Virus::charge(Map map)
{
	updateDelay = 0.03;
	if (position.getX() < toX)
	{
		updateNewPosition(map, position.getX() + 1, position.getY());
	}
	else if (position.getX() > toX)
	{
		updateNewPosition(map, position.getX() - 1, position.getY());
	}
	else
	{
		loopPart++;
	}
}