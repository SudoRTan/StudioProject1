#include "UI.h"
#include "Entity.h"
#include <iostream>

UI::UI()
{

}


UI::~UI()
{

}

void UI::splashScreen(Console& console)
{
	for (int i = 0; i < 24; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			console.writeToBuffer(j, i, EMPTY, FG_BLACK);
			
		}
	}

	console.writeToBuffer(35, 10, "2020 Vision", FG_WHITE); // positions tbc
	console.writeToBuffer(35, 12, "Play Game", FG_WHITE);
	console.writeToBuffer(35, 14, "Level Select", FG_WHITE);
};

void UI::render(Console& console, Player& player/*,Weapons& weapons*/)
{

	
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 80; j++) {
			console.writeToBuffer(j, i, EMPTY, FG_BLACK);
		}
	}


	int currentHealth = player.getHealth() * 2;
	int currentAmmo = player.getAmmo() * 2;
	

	console.writeToBuffer(1, 1, "Health: ", FG_WHITE);
	if (currentAmmo != -2) {
		console.writeToBuffer(1, 4, "Ammo: ", FG_WHITE);
	}

	for (int i = 0; i < 40; i++) {
		if (i < currentHealth) {
			console.writeToBuffer(1 + i, 2, (char)FLOOR, FG_RED);
		}
		else {
			console.writeToBuffer(1 + i, 2, (char)FLOOR, FG_GRAY);
		}

		if (currentAmmo != -2)
		{
			if (i < currentAmmo) {
				console.writeToBuffer(1 + i, 5, (char)FLOOR, FG_YELLOW);
			}
			else {
				console.writeToBuffer(1 + i, 5, (char)FLOOR, FG_GRAY);
			}
		}
	}
	
 };

