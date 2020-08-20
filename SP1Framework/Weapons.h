#pragma once
#include"Framework/console.h"
#include "Player.h"

class Weapons
{
public:
	int ammo;
	int getAmmo();
	int setAmmo(int newammo);
	//constructor & destructor
	Weapons();
	~Weapons();

private:
	void gun(Player& player);
	void sword(Player& player);
	int shoot();
	int reload();  
	void WeaponSwitch();
}; 


