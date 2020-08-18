#include "Weapons.h"

Weapons::Weapons()
{
	int ammo = 30;
}

Weapons::~Weapons()
{

}

void Weapons::gun()
{


}

int Weapons::shoot()
{


}

int Weapons::reload()
{
	if (int(ammo) == 0)
	ammo = ammo + 30;

}

	

void Weapons::sword()
{


}


int Weapons::getAmmo()
{
	return ammo;
}

