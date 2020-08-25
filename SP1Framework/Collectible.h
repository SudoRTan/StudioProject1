#pragma once
#include "Player.h"
#include "Entity.h"

class Collectible
	: public Entity
{
protected:
	std::string type;

public:
	Collectible(int x, int y);
	virtual ~Collectible();
	//void PlayerCollect(Position playerpos); // use playerpos obj in Player.h as parameter for comparing when player's position is the same as collectible's position
	
	virtual void update(Map& map);
	std::string getType();


};

Collectible* getCollectible(int x, int y, Collectible** collectible, int arraySize);