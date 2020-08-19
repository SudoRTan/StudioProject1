#pragma once
#include "Player.h"
#include "Framework/console.h"
#include "Weapons.h"


class UI
{
 public:
	 //Constructor & Destructor
	 UI();
	 ~UI();
	 void HealthBar(Console& console, Player& player);
	 void MaxHealth();
	 int HealthReduce(Player& player); 
	
};

