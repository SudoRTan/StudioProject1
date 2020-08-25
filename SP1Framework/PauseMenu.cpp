#include "PauseMenu.h"


PauseMenu::PauseMenu() {
	currentSelection = 1;
	totalSelections = 2;
}

PauseMenu::~PauseMenu() {

}

void PauseMenu::update(int& gameState, SKeyEvent KeyEvent[K_COUNT], int& currStage, int& currLevel) {
	if (KeyEvent[K_DOWN].keyOnce) {
		currentSelection++;
		if (currentSelection > totalSelections) {
			currentSelection = 1;
		}
	}
	else if (KeyEvent[K_UP].keyOnce) {
		currentSelection--;
		if (currentSelection == 0) {
			currentSelection = totalSelections;
		}
	}
	else if (KeyEvent[K_SPACE].keyOnce) {
		if (currentSelection == 1) {
			gameState = RESUME_LEVEL;
		}
		else {
			gameState = START_MENU;
		}
	}
	else if (KeyEvent[K_ESCAPE].keyOnce) {
		gameState = RESUME_LEVEL;

	}
}



void PauseMenu::render(Console& console) {
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
	if (currentSelection == 1) {
		console.writeToBuffer(12, 12, "RESUME", FG_RED);
		console.writeToBuffer(12, 14, "EXIT TO MAIN MENU", FG_WHITE);
	}

	else if (currentSelection == 2) {
		console.writeToBuffer(12, 12, "RESUME", FG_WHITE);
		console.writeToBuffer(12, 14, "EXIT TO MAIN MENU", FG_RED);
	}


}
