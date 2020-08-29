#include "BossStage4People.h"

int BossStage4People::personCount = 0;

BossStage4People::BossStage4People() : projectile{0}
{
	updateDelay = 3;
	lastMoveTime = 0;
	shotsFired = 0;
	cleanUp();
	personType = personCount;
	switch (personType)
	{
	case GUNMAN:
		position.setX(0);
		position.setY(1);
		lastMoveTime = 0;
		height = 3;
		width = 2;
		symbolArray = createArray(width, height);
		symbolArray[0][0] = (char)65;
		symbolArray[0][1] = (char)124;
		symbolArray[0][2] = (char)79;
		symbolArray[1][0] = (char)32;
		symbolArray[1][1] = (char)169;
		symbolArray[1][2] = (char)32;
		break;
	case KNIFEMAN:
		position.setX(79);
		position.setY(1);
		setDamage(10);
		lastMoveTime = 1000;
		height = 3;
		width = 3;
		symbolArray = createArray(width, height);
		symbolArray[0][0] = (char)32;
		symbolArray[0][1] = (char)196;
		symbolArray[0][2] = (char)32;
		symbolArray[1][0] = (char)32;
		symbolArray[1][1] = (char)199;
		symbolArray[1][2] = (char)32;
		symbolArray[2][0] = (char)65;
		symbolArray[2][1] = (char)124;
		symbolArray[2][2] = (char)79;
		break;
	}
	personCount++;
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
		if (g_dElapsedTime - lastMoveTime > 3)
		{
			if (shotsFired == 0)
			{
				projectile[0] = new Projectile(position.getX() + 1, position.getY(), RIGHT, 5, (char)254, 0.05);
				lastMoveTime = g_dElapsedTime;
				shotsFired++;
			}
			else if (shotsFired == 1)
			{
				projectile[1] = new Projectile(position.getX() + 1, position.getY(), RIGHT, 5, (char)254, 0.05);
				lastMoveTime = g_dElapsedTime;
				shotsFired++;
			}
		}
		for (int i = 0; i < 2; i++)
			if (projectile[i] != nullptr)
				if (player.isLocatedAt(projectile[i]->getPositionX(), projectile[i]->getPositionY()))
				{
					player.takeDamage(projectile[i]->getDamage());
					delete projectile[i];
					projectile[i] == nullptr;
				}
				else
					projectile[i]->update(map, g_dElapsedTime, &player);
	}
	else if (personType == KNIFEMAN)
	{
		if (player.getHealth() == 10)
		{
			lastMoveTime = g_dElapsedTime;
		}
		if (g_dElapsedTime - lastMoveTime > updateDelay)
		{
			updateDelay = 0.03;
			if (position.getX() > 0)
				updateNewPosition(map, position.getX() - 1, position.getY());
		}
	}
	return NO_CHANGE;
}