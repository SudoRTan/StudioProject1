#pragma once
#include "Entity.h"

class Player;

class Collectible
	: public Entity
{
protected:
	int type;
	bool collected;

public:
	Collectible(int x, int y);
	virtual ~Collectible();
	//void PlayerCollect(Position playerpos); // use playerpos obj in Player.h as parameter for comparing when player's position is the same as collectible's position
	
	virtual void update(Map& map);
	int getType();

	void collect();

	bool isCollected();
};

Collectible* getCollectible(int x, int y, Collectible** collectible, int arraySize);