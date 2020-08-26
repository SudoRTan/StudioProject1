#pragma once
#include "Collectible.h"
class HealthCollectible
	: public Collectible
{
private:
public:
	HealthCollectible(int x, int y);
	~HealthCollectible();


	void update(Map& map);
};

