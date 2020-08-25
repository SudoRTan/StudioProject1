#include "Collectible.h"

Collectible::Collectible(int x, int y)
{
	isCollected = false;
	position.setX(x); // set collectible's position on map to (7,7) for testing purposes
	position.setY(y);
}

Collectible::~Collectible()
{

}
/*
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
*/

void Collectible::update(Map& map) {
	map.setTempItem(position.getX(), position.getY(), 'C');
}