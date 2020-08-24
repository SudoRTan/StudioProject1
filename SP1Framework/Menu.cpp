#include "Menu.h"



Menu::Menu() {
}

Menu::~Menu() {

}

void Menu::update(int gameState, SKeyEvent KeyEvent[K_COUNT]) {

}

void Menu::render(int gameState, Console& console) {
	switch (gameState) {
	case PAUSE_MENU:
		renderPauseMenu(console);
		break;
	
	default:
		break;
	}
}


void Menu::renderPauseMenu(Console& console) {

	std::string line;
	std::ifstream pauseText("pauseButton.txt");
	int linecount = 0;

	if (pauseText.is_open()) {
		while (std::getline(pauseText, line)) {
			console.writeToBuffer(9, 5 + linecount, line, FG_BLUE);
			linecount++;
		}
		pauseText.close();
	}

}