#pragma once
#include "Player.h"
using namespace std;

class UI
{
 public:
	 //Constructor & Destructor
	 UI();
	 ~UI();
	 int HealthBar(Player& player);
	 void MaxHealth();
	 //int HealthReduce();
	
};

