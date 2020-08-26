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



/*void PauseMenu::render(Console& console) {
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


}*/

void PauseMenu::render(Console& console)
{
	// Initialize variables to load pause button box
	std::string boxLine;
	std::ifstream boxFile("pauseMenuBox.txt");
	int boxLinecount = 0;
	
	//Load pause button box
	if (boxFile.is_open()) {
		while (std::getline(boxFile, boxLine)) {
			console.writeToBuffer(12, 12 + boxLinecount, boxLine, FG_RED + BG_WHITE);
			boxLinecount++;
		}
		boxFile.close();
	}
	boxLinecount = 0;


	// Initialize variables to load pause button
	std::string pauseButtonLine;
	std::ifstream pauseButtonFile("pauseButton.txt");
	int pauseButtonLineCount = 0;

	//Load pause button
	if (pauseButtonFile.is_open()) {
		while (std::getline(pauseButtonFile, pauseButtonLine)) {
			console.writeToBuffer(8, 1 + pauseButtonLineCount, pauseButtonLine, FG_RED + BG_WHITE);
			pauseButtonLineCount++;
		}
		pauseButtonFile.close();
	}
	pauseButtonLineCount = 0;

	//First option Selected
	if (currentSelection == 1) {
		console.writeToBuffer(17, 14, "RESUME", FG_RED);
		console.writeToBuffer(53, 14, "MAIN MENU", FG_WHITE);
	}

	//Second Option selected
	else {
		console.writeToBuffer(17, 14, "RESUME", FG_WHITE);
		console.writeToBuffer(53, 14, "MAIN MENU", FG_RED);
	}
	
    
}



 