#include "HealthCollectible.h"

HealthCollectible::HealthCollectible(int x, int y) :Collectible(x, y)
{
	type = HEALTH;


	height = 1;
	width = 1;

	symbolArray = createArray(height, width);

	symbolArray[0][0] = 'H';

}

HealthCollectible::~HealthCollectible()
{
	cleanUp();
}

void HealthCollectible::update(Map& map) {
	updateNewPosition(map, position.getX(), position.getY());

}