#include "BossStage1Fire.h"

BossStage1Fire::BossStage1Fire()
{
	position.setX(4 * (rand() % 5));
	position.setY(1 + 5 * (rand() % 24));
	setHealth(3);
}

BossStage1Fire::~BossStage1Fire()
{

}

void BossStage1Fire::takeDamage(Player player)
{
	if (player.getPositionX() == position.getX() && player.getPositionY() == position.getY())
	{
		//kill player
	}
	else if (player.getPositionX() - position.getX() < 5 && player.getPositionX() - position.getX() > -5) //add function to check if shoot is true
	{
		health--;
	}
}