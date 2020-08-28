#include "BossStage3Virus.h"

BossStage3Virus::BossStage3Virus() : projectileArray{nullptr}
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
	caseLoop = SHOOT_LOOP;
	shootLoopCount = 0;
	lastShootTime = 0;
	completedAction = false;
}

BossStage3Virus::~BossStage3Virus()
{
	cleanUp();
}

int BossStage3Virus::update(Map& map, double g_dElapsedTime, Player& player)
{
	updateNewPosition(map, position.getX(), position.getY());
	if (contactPlayer(position.getX(), position.getY(), player) == true)
		player.takeDamage(getDamage());
	if (caseLoop == SHOOT_LOOP)
	{
		if (mode == MOVING)
		{
			move(player);
			if (completedAction == true)
				mode = SHOOTING;
		}
		else if (mode == SHOOTING)
		{
			shoot(g_dElapsedTime);
			if (completedAction == true)
			{
				mode = MOVING;
				shootLoopCount++;
			}
			if (shootLoopCount == 3)
				switch (rand() % 2)
				{
				case 0:
					caseLoop = SHOOT_LOOP;
					break;
				case 1:
					caseLoop = CHARGE_LOOP;
					break;
				}
		}
	}
	else if (caseLoop == CHARGE_LOOP)
	{
		if (mode == MOVING)
		{
			move(player);
			if (completedAction == true)
				mode = CHARGING;
		}
		else if (mode == CHARGING)
		{
			charge();
			if (completedAction == true)
				switch (rand() % 2)
				{
				case 0:
					caseLoop = SHOOT_LOOP;
					break;
				case 1:
					caseLoop = CHARGE_LOOP;
					break;
				}
		}
	}
	for (int i = 0; i < 3; i++)
		if (projectileArray[i] != nullptr)
			projectileArray[i]->update(map, g_dElapsedTime, &player);
	return NO_CHANGE;
}

void BossStage3Virus::move(Player player)
{
	completedAction = false;
	if (position.getY() - player.getPositionY() < 0) //require testing to see if possible to shoot boss while constantly moving to keep boss in infinite move loop
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

void BossStage3Virus::shoot(double g_dElapsedTime)
{
	completedAction = false;
	if (g_dElapsedTime - lastShootTime > 0.7)
	{
		if (projectileArray[0] == nullptr)
		{
			if (direction == LEFT)
				projectileArray[0] = new Projectile(position.getX() - 1, position.getY(), direction, 3, (char)254, 0.07);
			else if (direction == RIGHT)
				projectileArray[0] = new Projectile(position.getX() + 1, position.getY(), direction, 3, (char)254, 0.07);
			lastShootTime = g_dElapsedTime;
			completedAction = true;
		}
		else if (projectileArray[1] == nullptr)
		{
			if (direction == LEFT)
				projectileArray[1] = new Projectile(position.getX() - 1, position.getY(), direction, 3, (char)254, 0.07);
			else if (direction == RIGHT)
				projectileArray[1] = new Projectile(position.getX() + 1, position.getY(), direction, 3, (char)254, 0.07);
			lastShootTime = g_dElapsedTime;
			completedAction = true;
		}
		else if (projectileArray[2] == nullptr)
		{
			if (direction == LEFT)
				projectileArray[2] = new Projectile(position.getX() - 1, position.getY(), direction, 3, (char)254, 0.07);
			else if (direction == RIGHT)
				projectileArray[2] = new Projectile(position.getX() + 1, position.getY(), direction, 3, (char)254, 0.07);
			lastShootTime = g_dElapsedTime;
			completedAction = true;
		}
	}
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