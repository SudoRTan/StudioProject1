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
			gameState = IN_LEVEL;
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

	console.writeToBuffer(10, 8, "[Up/Down]Select Stage [Esc]Back to Title Screen", FG_WHITE);

	if (selectedStage) {
		for (int i = 0; i < totalSelections; i++) {
			if (i + 1 == currentSelection) {
				console.writeToBuffer(10, 10 + i, "Stage: " + std::to_string(i + 1), FG_RED);
			}

			else {
				console.writeToBuffer(10, 10 + i, "Stage: " + std::to_string(i + 1), FG_WHITE);
			}
		}
	}

	else {
		for (int i = 0; i < totalStage; i++) {
			if (i + 1 == currentSelection) {
				console.writeToBuffer(10, 10 + i, "Stage: " + std::to_string(i + 1), FG_RED);
			}

			else {
				console.writeToBuffer(10, 10 + i, "Stage: " + std::to_string(i + 1), FG_WHITE);
			}
		}
	}
}