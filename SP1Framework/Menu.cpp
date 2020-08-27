#include "Menu.h"


Menu::Menu() {
	//Constructor left intentionally blank
}

Menu::~Menu() {
	//Destructor left intentionally blank
}


void Menu::increaseSelection(int numberOfOptions) {
	currentSelection++;

	if (numberOfOptions != 0) {
		if (currentSelection > numberOfOptions) {
			currentSelection = 1;
		}
	}
	else {
		if (currentSelection > totalSelections) {
			currentSelection = 1;
		}
	}
	
}

void Menu::decreaseSelection(int numberOfOptions) {
	currentSelection--;

	if (numberOfOptions != 0) {
		if (currentSelection == 0) {
			currentSelection = numberOfOptions;
		}
	}
	else {
		if (currentSelection == 0) {
			currentSelection = totalSelections;
		}
	}
}
