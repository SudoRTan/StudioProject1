#include "DeathMenu.h"

DeathMenu::DeathMenu() {
	currentSelection = 1;
	totalSelections = 2;
}

DeathMenu::~DeathMenu() {

}


void DeathMenu::update(int& gameState, SKeyEvent KeyEvent[K_COUNT], int& currStage, int& currLevel) {
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
			gameState = RELOAD_LEVEL;
		}
		else {
			gameState = START_MENU;
		}
	}
	else if (KeyEvent[K_ESCAPE].keyOnce) {
		gameState = START_MENU;

	}



}


/*void DeathMenu::render(Console& console) {
	std::string line;
	std::ifstream file("deathScreen.txt");
	int linecount = 0;

	if (file.is_open()) {
		while (std::getline(file, line)) {
			console.writeToBuffer(12, 2 + linecount, line, FG_RED + BG_WHITE);
			linecount++;
		}
		file.close();
	}

	

	if (currentSelection == 1) {
		console.writeToBuffer(14, 15, "TRY AGAIN", FG_RED);
		console.writeToBuffer(14, 17, "EXIT TO MAIN MENU", FG_WHITE);
	}

	else if (currentSelection == 2) {
		console.writeToBuffer(14, 15, "TRY AGAIN" , FG_WHITE);
		console.writeToBuffer(14, 17, "EXIT TO MAIN MENU", FG_RED);
	}

}*/

void DeathMenu::render(Console& console) {

	std::string boxLine;
	std::ifstream boxFile("deathMenuBox.txt");
	int boxLinecount = 0;

	if (boxFile.is_open()) {
		while (std::getline(boxFile, boxLine)) {
			console.writeToBuffer(12, 14 + boxLinecount, boxLine, FG_RED + BG_WHITE);
			boxLinecount++;
		}
		boxFile.close();
	}
	boxLinecount = 0;

	std::string pauseButtonLine;
	std::ifstream pauseButtonFile("deathScreen.txt");
	int pauseButtonLineCount = 0;

	if (pauseButtonFile.is_open()) {
		while (std::getline(pauseButtonFile, pauseButtonLine)) {
			console.writeToBuffer(11, 1 + pauseButtonLineCount, pauseButtonLine, FG_RED + BG_WHITE);
			pauseButtonLineCount++;
		}
		pauseButtonFile.close();
	}
	pauseButtonLineCount = 0;

	if (currentSelection == 1) {
		console.writeToBuffer(15, 16, "TRY AGAIN", FG_RED);
		console.writeToBuffer(53, 16, "MAIN MENU", FG_WHITE);
	}
	else {
		console.writeToBuffer(15, 16, "TRY AGAIN", FG_WHITE);
		console.writeToBuffer(53, 16, "MAIN MENU", FG_RED);
	}
}