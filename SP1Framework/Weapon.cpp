#include "Weapon.h"

Weapon::Weapon()
{
	int ammo = 30;
   
}

Weapon::~Weapon()
{

}

void Weapon::gun(Player& player)
{
	

}

int Weapon::shoot()
{
	if (int(ammo) > 0)
	ammo = ammo - 1;
	return ammo;
}

int Weapon::reload()
{
    if (int(ammo) == 0)
	ammo = ammo + 30;
    return ammo;
	
}

int Weapon:: setAmmo(int newammo)
{
	ammo = newammo;
	return ammo;
}
	
void Weapon::sword(Player& player)
{
	
	
}


int Weapon::getAmmo()
{
	return ammo;
}

void Weapon::WeaponSwitch()
{
    

}

