#include "Collectible.h"

Collectible::Collectible(int x, int y)
{
	//isCollected = false;
	
	
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


std::string Collectible::getType() {
	return type;
}



Collectible* getCollectible(int x, int y, Collectible** collectible, int arraySize) {
	Collectible* returnCollectible = nullptr;

	if (collectible != nullptr) {
		for (int i = 0; i < arraySize; i++) {
			if (collectible[i] != nullptr) {
				if (collectible[i]->isLocatedAt(x, y)) {
					returnCollectible = collectible[i];
				}
			}
		}
	}


	return returnCollectible;
}


