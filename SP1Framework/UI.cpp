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

	console.writeToBuffer(40, 10, "2020 Vision", FG_WHITE); // positions tbc
	console.writeToBuffer(40, 14, "Play", FG_WHITE);
	console.writeToBuffer(40, 16, "Level Select", FG_WHITE);
};

void UI::render(Console& console, Player& player)
{
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 80; j++) {
			console.writeToBuffer(j, i, EMPTY, FG_BLACK);
		}
	}


	int currentHealth = player.getHealth() * 2;
	//float hiddenHealth = 10 - visibleHealth;


	console.writeToBuffer(1, 1, "Health: ", FG_WHITE);
	console.writeToBuffer(1, 4, "Ammo: ", FG_WHITE);

	for (int i = 0; i < 40; i++) {
		if (i < currentHealth) {
			console.writeToBuffer(1 + i, 2, FLOOR, FG_RED);
		}
		else {
			console.writeToBuffer(1 + i, 2, FLOOR, FG_GRAY);
		}

		console.writeToBuffer(1 + i, 5, FLOOR, FG_YELLOW);

	}
};

