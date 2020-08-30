#include "PauseMenu.h"


PauseMenu::PauseMenu() {
	currentSelection = 1;
	totalSelections = 3;
}

PauseMenu::~PauseMenu() {

}

void PauseMenu::update(int& gameState, SKeyEvent KeyEvent[K_COUNT], int& currStage, int& currLevel, int unlockedStage, int unlockedLevel) {
	if (KeyEvent[K_UP].keyOnce || KeyEvent[K_LEFT].keyOnce) {
		decreaseSelection();
		PlaySound(TEXT("./Sounds/menuSelect.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}

	else if (KeyEvent[K_DOWN].keyOnce || KeyEvent[K_RIGHT].keyOnce) {
		increaseSelection();
		PlaySound(TEXT("./Sounds/menuSelect.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}
	
	else if (KeyEvent[K_SPACE].keyOnce) {
		if (currentSelection == 1) {
			gameState = RESUME_LEVEL;
			PlaySound(TEXT("./Sounds/menuConfirm.wav"), NULL, SND_FILENAME | SND_ASYNC);
		}

		else if (currentSelection == 2) {
			gameState = HELP_MENU;
			PlaySound(TEXT("./Sounds/menuConfirm.wav"), NULL, SND_FILENAME | SND_ASYNC);	
		}

		else {
			currentSelection = 1;
			gameState = START_MENU;
			PlaySound(TEXT("./Sounds/menuConfirm.wav"), NULL, SND_FILENAME | SND_ASYNC);
		}
	}
	else if (KeyEvent[K_ESCAPE].keyOnce) {
		currentSelection = 1;
		gameState = RESUME_LEVEL;
		PlaySound(TEXT("./Sounds/menuEscape.wav"), NULL, SND_FILENAME | SND_ASYNC);

	}
}




void PauseMenu::render(Console& console)
{
	// Initialize variables to load pause button box
	std::string boxLine;
	std::ifstream boxFile("ASCIIArt\\pauseMenuBox.txt");
	int boxLinecount = 0;
	
	//Load pause button box
	if (boxFile.is_open()) {
		while (std::getline(boxFile, boxLine)) {
			console.writeToBuffer(4, 12 + boxLinecount, boxLine, FG_RED + BG_WHITE);
			boxLinecount++;
		}
		boxFile.close();
	}
	boxLinecount = 0;


	// Initialize variables to load pause button
	std::string pauseButtonLine;
	std::ifstream pauseButtonFile("ASCIIArt\\pauseButton.txt");
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
		console.writeToBuffer(9, 14, "RESUME", FG_RED);
		console.writeToBuffer(37, 14, "HELP", FG_WHITE);
		console.writeToBuffer(63, 14, "MAIN MENU", FG_WHITE);
	}

	//Second Option selected
	if (currentSelection == 2) {
		console.writeToBuffer(9, 14, "RESUME", FG_WHITE);
		console.writeToBuffer(37, 14, "HELP", FG_RED);
		console.writeToBuffer(63, 14, "MAIN MENU", FG_WHITE);
	}
	//Third Option selected
	if (currentSelection == 3) {
		console.writeToBuffer(9, 14, "RESUME", FG_WHITE);
		console.writeToBuffer(37, 14, "HELP", FG_WHITE);
		console.writeToBuffer(63, 14, "MAIN MENU", FG_RED);

	}
}



 