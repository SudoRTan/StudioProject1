#include "Collectible.h"

Collectible::Collectible(int x, int y, int collectibleType)
{
	type = collectibleType;

	height = 1;
	width = 1;

	symbolArray = createArray(height, width);

	symbolArray[0][0] = collectibleType;

	position.setX(x); // set collectible's position on map to (7,7) for testing purposes
	position.setY(y);

	collected = false;
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
	map.setTempItem(position.getX(), position.getY(), type);
}


int Collectible::getType() {
	return type;
}

void Collectible::collect() {
	collected = true;
}

bool Collectible::isCollected() {
	return collected;
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


