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

	

void Weapons::sword()
{


}


int Weapons::getAmmo()
{
	return ammo;
}

void Weapons::AmmoCounter(Console& console)
{
	console.writeToBuffer(0, 1, (char)48, 'Ammo');
	float ShowAmmo = Weapons::getAmmo() / 10;
	float HiddenAmmo = 10 - ShowAmmo;
	{
		for (int i = 0; i < int(ShowAmmo); i++);
		console.writeToBuffer(6, 1, (char)48, '[0]');
		for (int i = 0; i < int(HiddenAmmo); i++);
		console.writeToBuffer(6, 1, (char)48, '[ ]');

	}

}