#include "Menu.h"


Menu::Menu() {
	//Constructor left intentionally blank
}

Menu::~Menu() {
	//Destructor left intentionally blank
}


void Menu::increaseSelection() {
	currentSelection++;
	if (currentSelection > totalSelections) {
		currentSelection = 1;
	}
}

void Menu::decreaseSelection() {
	currentSelection--;
	if (currentSelection == 0) {
		currentSelection = totalSelections;
	}
}
