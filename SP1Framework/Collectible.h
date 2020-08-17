#pragma once
#include "Player.h"
#include "Entity.h"

class Collectible
	: public Entity
{
private:
	bool isCollected;
	int CollectibleCount = 0;
	Position collectiblepos;

public:
	Collectible();
	~Collectible();
	void PlayerCollect(Position playerpos); // use playerpos obj in Player.h as parameter for comparing when player's position is the same as collectible's position
};

