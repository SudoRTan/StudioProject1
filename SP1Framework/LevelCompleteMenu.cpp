#include "LevelCompleteMenu.h"




LevelCompleteMenu::LevelCompleteMenu() {
	currentSelection = 1;
	totalSelections = 2;
}

LevelCompleteMenu::~LevelCompleteMenu() {

}

void LevelCompleteMenu::update(int& gameState, SKeyEvent KeyEvent[K_COUNT], int& currStage, int& currLevel, int unlockedStage, int unlockedLevel) {
	if (KeyEvent[K_UP].keyOnce || KeyEvent[K_LEFT].keyOnce) {
		decreaseSelection();
	}

	else if (KeyEvent[K_DOWN].keyOnce || KeyEvent[K_RIGHT].keyOnce) {
		increaseSelection();
		PlaySound(TEXT("./Sounds/menuSelect.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}

	else if (KeyEvent[K_SPACE].keyOnce) {
		if (currentSelection == 1) {
			gameState = NEXT_LEVEL;
			PlaySound(TEXT("./Sounds/menuConfirm.wav"), NULL, SND_FILENAME | SND_ASYNC);
		}
		else {
			currentSelection = 1;
			gameState = START_MENU;
			PlaySound(TEXT("./Sounds/menuConfirm.wav"), NULL, SND_FILENAME | SND_ASYNC);
		}
	}
	else if (KeyEvent[K_ESCAPE].keyOnce) {
		gameState = START_MENU;
		PlaySound(TEXT("./Sounds/menuEscape.wav"), NULL, SND_FILENAME | SND_ASYNC);

	}
}

void LevelCompleteMenu::render(Console& console) {
	std::string boxLine;
	std::ifstream boxFile("ASCIIArt\\levelCompleteMenuBox.txt");
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
	std::ifstream pauseButtonFile("ASCIIArt\\levelComplete.txt");
	int pauseButtonLineCount = 0;

	if (pauseButtonFile.is_open()) {
		while (std::getline(pauseButtonFile, pauseButtonLine)) {
			console.writeToBuffer(1, 1 + pauseButtonLineCount, pauseButtonLine, FG_RED + BG_WHITE);
			pauseButtonLineCount++;
		}
		pauseButtonFile.close();
	}
	pauseButtonLineCount = 0;

	if (currentSelection == 1) {
		console.writeToBuffer(15, 16, "NEXT LEVEL", FG_RED);
		console.writeToBuffer(53, 16, "MAIN MENU", FG_WHITE);
	}
	else {
		console.writeToBuffer(15, 16, "NEXT LEVEL", FG_WHITE);
		console.writeToBuffer(53, 16, "MAIN MENU", FG_RED);
	}
}