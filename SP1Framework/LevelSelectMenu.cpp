#include "LevelSelectMenu.h"


LevelSelectMenu::LevelSelectMenu() {
	currentSelection = 1;
	totalSelections = 3;


	totalStage = 3;


	selectedStage = 0;
}

LevelSelectMenu::~LevelSelectMenu() {

}

void LevelSelectMenu::update(int& gameState, SKeyEvent KeyEvent[K_COUNT], int& currStage, int& currLevel) {
	if (KeyEvent[K_DOWN].keyOnce) {
		if (selectedStage) {
			currentSelection++;
			if (currentSelection > totalSelections) {
				currentSelection = 1;
			}
		}
		else {
			currentSelection++;
			if (currentSelection > totalStage) {
				currentSelection = 1;
			}
		}

	}
	else if (KeyEvent[K_UP].keyOnce) {
		if (selectedStage) {
			currentSelection--;
			if (currentSelection == 0) {
				currentSelection = totalSelections;
			}
		}
		else {
			currentSelection--;
			if (currentSelection == 0) {
				currentSelection = totalStage;
			}
		}
	}
	else if (KeyEvent[K_SPACE].keyOnce) {
		if (selectedStage) {
			currStage = selectedStage;
			currLevel = currentSelection;
			selectedStage = 0;
			currentSelection = 1;
			gameState = LOAD_LEVEL;
		}
		else {
			selectedStage = currentSelection;
			currentSelection = 1;
		}
	}
	else if (KeyEvent[K_ESCAPE].keyOnce) {
		if (selectedStage) {
			selectedStage = 0;
			currentSelection = 1;
		}
		else {
			gameState = START_MENU;
		}
	}
}

void LevelSelectMenu::render(Console& console) {

	console.writeToBuffer(14, 9, "[Up/Down]Select Stage [Esc]Back to Title Screen", FG_WHITE);

	std::string boxLine;
	std::ifstream boxFile("boxMenu.txt");
	int boxLinecount = 0;

	if (boxFile.is_open()) {
		while (std::getline(boxFile, boxLine)) {
			console.writeToBuffer(4, 12 + boxLinecount, boxLine, FG_RED + BG_WHITE);
			boxLinecount++;
		}
		boxFile.close();
	}
	boxLinecount = 0;

	if (selectedStage) {

		std::string line;
		std::ifstream nameFile("levelMenu.txt");
		int linecount = 0;

		if (nameFile.is_open()) {
			while (std::getline(nameFile, line)) {
				console.writeToBuffer(4, 1 + linecount, line, FG_RED + BG_WHITE);
				linecount++;
			}
			nameFile.close();
		}
		linecount = 0;

		for (int i = 0; i < totalSelections; i++) {
			if (i + 1 == currentSelection) {
				console.writeToBuffer(8 + (i * 27), 14, "Level: " + std::to_string(i + 1), FG_RED);
			}

			else {
				console.writeToBuffer(8 + (i * 27), 14, "Level: " + std::to_string(i + 1), FG_WHITE);
			}
		}
	}

	else {

		std::string line;
		std::ifstream nameFile("stageMenu.txt");
		int linecount = 0;

		if (nameFile.is_open()) {
			while (std::getline(nameFile, line)) {
				console.writeToBuffer(2, 1 + linecount, line, FG_RED + BG_WHITE);
				linecount++;
			}
			nameFile.close();
		}
		linecount = 0;

		for (int i = 0; i < totalStage; i++) {
			if (i + 1 == currentSelection) {
				console.writeToBuffer(8 + (i * 27), 14, "Stage: " + std::to_string(i + 1), FG_RED);
			}

			else {
				console.writeToBuffer(8 + (i * 27), 14, "Stage: " + std::to_string(i + 1), FG_WHITE);
			}
		}
	}
}