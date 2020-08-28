#pragma once
#include "Entity.h"
#include "Enemy.h"

class Player;

class Projectile :
	public Entity
{

private:



public:
	Projectile(int x, int y, int direction);
	Projectile(int x, int y, int direction, int damage);
	Projectile(int x, int y, int direction, int damage, char projectileSymbol, double speed);
	~Projectile();


	void update(Map& map, double elapsedTime, Player* player);
	void update(Map& map, double elapsedTime, Enemy** enemyArray, int enemyArraySize);

};

