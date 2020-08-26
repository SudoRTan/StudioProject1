#pragma once
#include "Entity.h"
#include "Enemy.h"

class Projectile :
	public Entity
{

private:



public:
	Projectile(int x, int y, int direction);
	~Projectile();

	void update(Map& map, double elapsedTime);

};

