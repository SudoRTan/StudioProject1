#include "Collectible.h"

Collectible::Collectible()
{
	isCollected = false;
	collectiblepos.setX(7);
	collectiblepos.setY(7);
}

Collectible::~Collectible()
{

}

void Collectible::PlayerCollect(Position playerpos)
{
	if ((playerpos.getX() == collectiblepos.getX()) && (playerpos.getY() == collectiblepos.getY())) // check if player moves over collectible
	{
		CollectibleCount++;
		isCollected = true;
		// overwrites previous x pos of collectible to blank cell
		//remove collectible from the map where the player currently is
	}
}