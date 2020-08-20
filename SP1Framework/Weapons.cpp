#include "Weapons.h"

Weapons::Weapons()
{
	int ammo = 30;
   
}

Weapons::~Weapons()
{

}

void Weapons::gun(Player& player)
{
	

}

int Weapons::shoot()
{
	if (int(ammo) > 0)
	ammo = ammo - 1;
	return ammo;
}

int Weapons::reload()
{
    if (int(ammo) == 0)
	ammo = ammo + 30;
    return ammo;
	
}

int Weapons:: setAmmo(int newammo) 
{
	ammo = newammo;
	return ammo;
}
	
void Weapons::sword(Player& player)
{
	
	
}


int Weapons::getAmmo()
{
	return ammo;
}

void Weapons::WeaponSwitch()
{
    

}

