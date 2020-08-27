#include "LevelSelectMenu.h"


LevelSelectMenu::LevelSelectMenu() {
	currentSelection = 1;
	totalSelections = 4;


	totalStage = 6;


	selectedStage = 0;
}

LevelSelectMenu::~LevelSelectMenu() { 

}

void LevelSelectMenu::update(int& gameState, SKeyEvent KeyEvent[K_COUNT], int& currStage, int& currLevel) {
	
	// If Stage is selected
	if (selectedStage) {
		if (KeyEvent[K_DOWN].keyOnce) {
			increaseSelection();
		}


		else if (KeyEvent[K_UP].keyOnce) {
			decreaseSelection();
		}


		else if (KeyEvent[K_SPACE].keyOnce) {
			currStage = selectedStage;
			currLevel = currentSelection;
			selectedStage = 0;
			currentSelection = 1;
			gameState = LOAD_LEVEL;
		}
		else if (KeyEvent[K_ESCAPE].keyOnce) {
			selectedStage = 0;
			currentSelection = 1;

		}
	}
	// If Stage is not selected
	else {
		if (KeyEvent[K_DOWN].keyOnce) {
			increaseSelection(totalStage);
		}

		else if (KeyEvent[K_UP].keyOnce) {
			decreaseSelection(totalStage);
		}

		else if (KeyEvent[K_SPACE].keyOnce) {
			selectedStage = currentSelection;
			currentSelection = 1;

		}

		else if (KeyEvent[K_ESCAPE].keyOnce) {
			gameState = START_MENU;

		}
		
	}
	


}

void LevelSelectMenu::render(Console& console) {

	console.writeToBuffer(14, 9, "[Up/Down]Select Stage [Esc]Back to Title Screen", FG_WHITE);

	if (selectedStage) {

		std::string boxLine;
		std::ifstream boxFile("levelBoxes.txt");
		int boxLinecount = 0;

		if (boxFile.is_open()) {
			while (std::getline(boxFile, boxLine)) {
				console.writeToBuffer(4, 12 + boxLinecount, boxLine, FG_RED + BG_WHITE);
				boxLinecount++;
			}
			boxFile.close();
		}
		boxLinecount = 0;

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
			if (i < 3) {
				if (i + 1 == currentSelection) {
					console.writeToBuffer(8 + (i * 27), 14, "Level: " + std::to_string(i + 1), FG_RED);
				}

				else {
					console.writeToBuffer(8 + (i * 27), 14, "Level: " + std::to_string(i + 1), FG_WHITE);
				}
			}
			else {
				if (i + 1 == currentSelection) {
					console.writeToBuffer(35, 20, "Level: " + std::to_string(i + 1), FG_RED);
				}

				else {
					console.writeToBuffer(35, 20, "Level: " + std::to_string(i + 1), FG_WHITE);
				}
			}
		}
	}

	else {

		std::string boxLine;
		std::ifstream boxFile("stageBoxes.txt");
		int boxLinecount = 0;

		if (boxFile.is_open()) {
			while (std::getline(boxFile, boxLine)) {
				console.writeToBuffer(4, 12 + boxLinecount, boxLine, FG_RED + BG_WHITE);
				boxLinecount++;
			}
			boxFile.close();
		}
		boxLinecount = 0;

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

			if (i < 3) {

				if (i + 1 == currentSelection) {
					console.writeToBuffer(8 + (i * 27), 14, "Stage: " + std::to_string(i + 1), FG_RED);
				}

				else {
					console.writeToBuffer(8 + (i * 27), 14, "Stage: " + std::to_string(i + 1), FG_WHITE);
				}
			}
			else {

				if (i + 1 == currentSelection) {
					console.writeToBuffer(8 + ((i - 3) * 27), 20, "Stage: " + std::to_string(i + 1), FG_RED);
				}

				else {
					console.writeToBuffer(8 + ((i - 3) * 27), 20, "Stage: " + std::to_string(i + 1), FG_WHITE);
				}
			}
		}
	}
}