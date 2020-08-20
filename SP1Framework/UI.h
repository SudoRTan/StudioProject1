#pragma once
#include "Player.h"
#include "Framework/console.h"
#include "Weapons.h"
#include "colors.h"


class UI
{
public:
	//Constructor & Destructor
	UI();
	~UI();


	void render(Console& console, Player& player,Weapons& weapons);
	void splashScreen(Console& console);

};

