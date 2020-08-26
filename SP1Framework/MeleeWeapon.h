#pragma once
#include "Weapon.h"

class MeleeWeapon :
	public Weapon
{
public:

	MeleeWeapon();
	~MeleeWeapon();

	void animate(Map& map, double elapsedTime, int direction, int x, int y);

	void use(Map& map, Enemy** enemyArray, int enemyArraySize, double elapsedTime, int direction, int x, int y);

	void update(Map& map, Enemy** enemyArray, int enemyArraySize, double elapsedTime, int direction, int x, int y, bool attacking);
};

enum MELEE_WEAPON_STATE {
	POINTING_UPWARDS = 47,
	POINTING_STRAIGHT = 95,
	POINTING_DOWNWARDS = 92
};