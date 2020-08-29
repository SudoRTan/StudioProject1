#pragma once
#include "Player.h"
#include "Framework/console.h"
#include "Weapon.h"
#include "colors.h"
#include <iostream>
#include <sstream>

class UI
{
public:
	//Constructor & Destructor
	UI();
	~UI();


	void render(Console& console, Player& player, int currStage, int currLevel);
	void splashScreen(Console& console);

};

