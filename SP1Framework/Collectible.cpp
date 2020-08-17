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

void Collectible::PlayerCollect()
{
	//if ((playerpos.getX() == collectiblepos.getX()) && (player.posY() == collectiblepos.getY())) // check if player moves over collectible
	//{
	//	CollectibleCount++;
	//	isCollected = true;
	//	collectiblepos.setX(0); // overwrites previous x pos of collectible to blank cell
	//	//removes collectible from the map where the player currently is
	//}
}