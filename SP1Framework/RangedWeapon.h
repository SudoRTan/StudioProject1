#pragma once
#include "Weapon.h"
#include "Projectile.h"

class RangedWeapon :
	public Weapon
{
private:
	Projectile* bullet;
	void animate(Map& map, double elapsedTime, int direction, int x, int y);
	void use(Map& map, Enemy** enemyArray, int enemyArraySize, double elapsedTime, int direction, int x, int y);

public:

	RangedWeapon();
	~RangedWeapon();



	void update(Map& map, Enemy** enemyArray, int enemyArraySize, double elapsedTime, int direction, int x, int y, bool attacking);

};

enum RANGED_WEAPON_STATE {
	R_POINTING_RIGHT = 169,
	R_POINTING_LEFT  = 170,
	
};


