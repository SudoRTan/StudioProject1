#include "LevelSelectMenu.h"


LevelSelectMenu::LevelSelectMenu() {
	currentSelection = 1;
	totalSelections = 4;


	totalStage = 6;


	selectedStage = 0;
}

LevelSelectMenu::~LevelSelectMenu() { 

}

void LevelSelectMenu::update(int& gameState, SKeyEvent KeyEvent[K_COUNT], int& currStage, int& currLevel, int unlockedStage, int unlockedLevel) {
	
	// If Stage is selected
	if (selectedStage) {
		// If up arrow is pressed
		if (KeyEvent[K_UP].keyOnce) {
			// Move cursor upwards if 4th option is currently selected
			if (currentSelection == 4) {
				currentSelection = 2;
			}
			PlaySound(TEXT("./Sounds/menuSelect.wav"), NULL, SND_FILENAME | SND_ASYNC);
		}
	
		// If down arrow is pressed
		else if (KeyEvent[K_DOWN].keyOnce) {
			// Move cursor downwards if 1st to 3rd option is currently selected
			if (currentSelection != 4) {
				currentSelection = 4;
			}
			PlaySound(TEXT("./Sounds/menuSelect.wav"), NULL, SND_FILENAME | SND_ASYNC);
		}

		// If left arrow is pressed
		else if (KeyEvent[K_LEFT].keyOnce) {
			// Move cursor left 
			decreaseSelection();
			PlaySound(TEXT("./Sounds/menuSelect.wav"), NULL, SND_FILENAME | SND_ASYNC);
		}

		// If right arrow is pressed
		else if (KeyEvent[K_RIGHT].keyOnce) {
			// Move cursor right
			increaseSelection();
			PlaySound(TEXT("./Sounds/menuSelect.wav"), NULL, SND_FILENAME | SND_ASYNC);
		}

		// If space is pressed
		else if (KeyEvent[K_SPACE].keyOnce) {
			// Sets selected stage and levels 
			currStage = selectedStage;
			currLevel = currentSelection;
			PlaySound(TEXT("./Sounds/menuConfirm.wav"), NULL, SND_FILENAME | SND_ASYNC);

			// Resets the menu variables for next use
			selectedStage = 0;
			currentSelection = 1;

			// Tell GameManager to load the selected level
			gameState = LOAD_LEVEL;
			
		}

		// If escape is pressed
		else if (KeyEvent[K_ESCAPE].keyOnce) {
			// Return to stage select Menu
			currentSelection = selectedStage;
			selectedStage = 0;
			PlaySound(TEXT("./Sounds/menuEscape.wav"), NULL, SND_FILENAME | SND_ASYNC);
		}

		if (selectedStage == unlockedStage) {
			if (currentSelection > unlockedLevel) {
				currentSelection = unlockedLevel;
			}
		}

	}
	// If Stage is not selected
	else {
		// If up arrow is pressed
		if (KeyEvent[K_UP].keyOnce) {
			if (currentSelection > 3) {
				currentSelection -= 3;
			}
			PlaySound(TEXT("./Sounds/menuSelect.wav"), NULL, SND_FILENAME | SND_ASYNC);
		}

		// If down arrow is pressed
		else if (KeyEvent[K_DOWN].keyOnce) {
			if (currentSelection <= 3) {
				currentSelection += 3;
			}
			PlaySound(TEXT("./Sounds/menuSelect.wav"), NULL, SND_FILENAME | SND_ASYNC);
		}

		// If left arrow is pressed
		else if (KeyEvent[K_LEFT].keyOnce) {
			decreaseSelection(totalStage);
			PlaySound(TEXT("./Sounds/menuSelect.wav"), NULL, SND_FILENAME | SND_ASYNC);
		}

		// If right arrow is pressed
		else if (KeyEvent[K_RIGHT].keyOnce) {
			increaseSelection(totalStage);
			PlaySound(TEXT("./Sounds/menuSelect.wav"), NULL, SND_FILENAME | SND_ASYNC);
		}

		// If space is pressed
		else if (KeyEvent[K_SPACE].keyOnce) {
			selectedStage = currentSelection;
			currentSelection = 1;
			PlaySound(TEXT("./Sounds/menuConfirm.wav"), NULL, SND_FILENAME | SND_ASYNC);
		}

		// If escape is pressed
		else if (KeyEvent[K_ESCAPE].keyOnce) {
			gameState = START_MENU;
			PlaySound(TEXT("./Sounds/menuEscape.wav"), NULL, SND_FILENAME | SND_ASYNC);
		}

		if (currentSelection > unlockedStage) {
			currentSelection = unlockedStage;
		}
	}
}

void LevelSelectMenu::render(Console& console) {

	console.writeToBuffer(14, 9, "[Arrow Keys]Select Stage [Esc]Back to Title Screen", FG_WHITE);

	if (selectedStage) {

		std::string boxLine;
		std::ifstream boxFile("ASCIIArt\\levelBoxes.txt");
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
		std::ifstream nameFile("ASCIIArt\\levelMenu.txt");
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
		std::ifstream boxFile("ASCIIArt\\stageBoxes.txt");
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
		std::ifstream nameFile("ASCIIArt\\stageMenu.txt");
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