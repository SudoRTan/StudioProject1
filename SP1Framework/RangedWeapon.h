#pragma once
#include "Weapon.h"

class RangedWeapon:
	public Weapon
{
public:

	RangedWeapon();
	~RangedWeapon();

	void animate(Map& map, double g_ElapsedTime, int direction, int x, int y);

	void use(Map& map,Enemy** enemyArray,int enemyArraySize, double g_ElapsedTime, int direction, int x, int y);

};

enum RANGED_WEAPON_STATE {
	POINTING_UPWARDS,
	POINTING_STRAIGHT,
	POINTING_DOWNWARDS,
};

