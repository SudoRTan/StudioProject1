#include "AprilFoolsMenu.h"


AprilFoolsMenu::AprilFoolsMenu() {
	currentSelection = 1;
	totalSelections = 2;
}

AprilFoolsMenu::~AprilFoolsMenu() {

}

void AprilFoolsMenu::render(Console& console) {
	if (currentSelection == 1) {
		std::string boxLine;
		std::ifstream boxFile("ASCIIArt\\deathMenuBox.txt");
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
		std::ifstream pauseButtonFile("ASCIIArt\\deathScreen.txt");
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
	else {
		std::string line;
		std::ifstream aprilFools("ASCIIArt\\aprilFools.txt");
		int lineCount = 0;

		if (aprilFools.is_open()) {
			while (std::getline(aprilFools, line)) {
				console.writeToBuffer(6, 1 + lineCount, line, FG_RED + BG_WHITE);
				lineCount++;
			}
			aprilFools.close();
		}

		console.writeToBuffer(25, 16, "PRESS ANY BUTTON TO CONTINUE", FG_RED);

	}
}

void AprilFoolsMenu::update(int& gameState, SKeyEvent KeyEvent[K_COUNT], int& currStage, int& currLevel, int unlockedStage, int unlockedLevel) {
	if (currentSelection == 1) {
		for (int i = 0; i < K_COUNT; i++) {
			if (KeyEvent[i].keyOnce) {
				currentSelection = 2;
			}
		}
	}
	else {
		if (KeyEvent[K_SPACE].keyOnce) {
			gameState = LEVEL_COMPLETE_MENU;
		}
	}
		
}
