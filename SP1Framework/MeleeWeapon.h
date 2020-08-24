#pragma once
#include "Weapon.h"

class MeleeWeapon :
	public Weapon
{
public:

	MeleeWeapon();
	~MeleeWeapon();

	void animate(Map& map, double g_dElapsedTime, int direction, int x, int y);

	void use(Map& map, Enemy** enemyArray, int enemyArraySize, double g_dElapsedTime, int direction, int x, int y);

};

enum MELEE_WEAPON_STATE {
	POINTING_UPWARDS = 47,
	POINTING_STRAIGHT = 95,
	POINTING_DOWNWARDS = 92
};