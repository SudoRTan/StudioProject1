#pragma once
#include "Weapon.h"

class RangedWeapon :
	public Weapon
{
public:

	RangedWeapon();
	~RangedWeapon();

	void animate(Map& map, double g_ElapsedTime, int direction, int x, int y);

	void use(Map& map, Enemy** enemyArray, int enemyArraySize, double g_ElapsedTime, int direction, int x, int y);

};

enum RANGED_WEAPON_STATE {
	R_POINTING_RIGHT = 169,
	R_POINTING_LEFT  = 170,
	
};


