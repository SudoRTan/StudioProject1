#include "Collectible.h"

Collectible::Collectible()
{
	isCollected = false;
	collectiblepos.setX(7); // set collectible's position on map to (7,7) for testing purposes
	collectiblepos.setY(7);
}

Collectible::~Collectible()
{

}

void Collectible::PlayerCollect(Position playerpos) // pass in player's position object into playerpos
{
	if ((playerpos.getX() == collectiblepos.getX()) && (playerpos.getY() == collectiblepos.getY())) // check if player moves over collectible
	{
		CollectibleCount++;
		isCollected = true;

		collectiblepos.setX(0);
		collectiblepos.setY(0);

		// overwrites previous x pos of collectible to blank cell
		//remove collectible from the map where the player currently is
	}
}