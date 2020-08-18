#pragma once
#include"Framework/console.h"
#include <Windows.h>

class Weapons
{
public:
	int ammo;
	int getAmmo();
	void AmmoCounter(Console& console);
	//constructor & destructor
	Weapons();
	~Weapons();

private:
	void gun();
	void sword();
	int shoot();
	int reload(); 
};  


