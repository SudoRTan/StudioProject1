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
	// checks if up/down arrow keys are pressed, if so then increment/decrement currentSelection var accordingly 
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
	// if space key is pressed, load menu/stage with corresponding highlighted text to indicate the option is "selected"
	//if esc key is pressed, change gamestate accordingly, and move console back to initial starting screen
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

	if (selectedStage) {

		// prints out ascii boxes for level select menu by reading from text file
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

		// prints out ascii art for level select menu by reading from text file
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

		// checks for current selection from above code. Prints out text for levels over ascii boxes. 
		//With current selection, highlight text in red to indicate it is selected. Else, display in normal white text.
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
		// prints out ascii boxes for stage select menu by reading from text file
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

		// prints out ascii art for stage select menu by reading from text file
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

		// same as above for printing out stage text and checking if text corresponds to current selection and highlighting in red or white.
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