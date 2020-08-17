#pragma once
#include "Player.h"
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
	void PlayerCollect();
};

