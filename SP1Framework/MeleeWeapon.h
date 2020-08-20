#pragma once
#include "Weapon.h"

class MeleeWeapon :
	public Weapon
{
public:

	MeleeWeapon();
	~MeleeWeapon();

	void use(Map& map);

};

