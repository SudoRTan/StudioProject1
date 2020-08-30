#include "BossStage5AlienBoss.h"

BossStage5AlienBoss::BossStage5AlienBoss()
{
	position.setX(77);
	position.setY(1);
	health = 30;
	updateDelay = 0.7;
	setDamage(20);
	height = 3;
	width = 3;
	direction = UP;
	symbolArray = createArray(width, height);
	symbolArray[0][0] = (char)32;
	symbolArray[0][1] = (char)32;
	symbolArray[0][2] = (char)183;
	symbolArray[1][0] = (char)196;
	symbolArray[1][1] = (char)254;
	symbolArray[1][2] = (char)219;
	symbolArray[2][0] = (char)32;
	symbolArray[2][1] = (char)32;
	symbolArray[2][2] = (char)189;
	toY = 1;
}

BossStage5AlienBoss::~BossStage5AlienBoss()
{
	cleanUp();
}

int BossStage5AlienBoss::update(Map& map, double g_dElapsedTime, Player& player)
{
	//moves boss to left
	if (position.getX() < 0)
		if (g_dElapsedTime - lastMovementTime < updateDelay)
			updateNewPosition(map, position.getX() - 1, position.getY());

	//moves boss side to side
	if (position.getY() == toY)
	{
		if (direction == UP)
		{
			direction = DOWN;
			toY = position.getY() + 3 + (rand() % 5);
			if (toY > 13)
			{
				toY = 13;
			}
		}
		else if (direction == DOWN)
		{
			direction = UP;
			toY = position.getY() - 3 - (rand() % 5);
			if (toY < 1)
			{
				toY = 1;
			}
		}
	}
	if (position.getY() < toY)
	{
		updateNewPosition(map, position.getX(), position.getY() + 1);
	}
	else if (position.getY() > toY)
	{
		updateNewPosition(map, position.getX(), position.getY() - 1);
	}

	//fire projectile
	if (position.getY() == toY)
		projectile.push_back(new Projectile(position.getX() - 1, position.getY() + 1, LEFT, 4, (char)196, 0.05));

	//check projectile location and update or delete accordingly
	for (int i = 0; i < projectile.size(); i++)
		if (projectile.at(i) != nullptr)
			if (player.isLocatedAt(projectile.at(i)->getPositionX(), projectile.at(i)->getPositionY()))
			{
				player.takeDamage(projectile.at(i)->getDamage());
				delete projectile.at(i);
				projectile.at(i) = nullptr;
			}
			else if (projectile.at(i)->getPositionX() == 0)
			{
				delete projectile.at(i);
				projectile.at(i) = nullptr;
			}
			else
				projectile.at(i)->update(map, g_dElapsedTime, &player);

	return NO_CHANGE;
}