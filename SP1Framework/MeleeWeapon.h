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

