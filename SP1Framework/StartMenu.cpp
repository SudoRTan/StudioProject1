#include "StartMenu.h"

StartMenu::StartMenu() {
	currentSelection = 1;
	totalSelections = 2;
}

StartMenu::~StartMenu() {

}

void StartMenu::update(int& gameState, SKeyEvent KeyEvent[K_COUNT], int& currStage, int& currLevel, int unlockedStage, int unlockedLevel) {
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
			gameState = LEVEL_SELECT;
			PlaySound(TEXT("./Sounds/menuConfirm.wav"), NULL, SND_FILENAME | SND_ASYNC);
		}
		if (currentSelection == 2){
			gameState = EXIT_GAME;
			PlaySound(TEXT("./Sounds/menuconfirm.wav"), NULL, SND_FILENAME | SND_ASYNC);
		}
	}
	else if (KeyEvent[K_ESCAPE].keyOnce) {
		gameState = EXIT_GAME;
		PlaySound(TEXT("./Sounds/menuEscape.wav"), NULL, SND_FILENAME | SND_ASYNC);
			
	}
	
}

void StartMenu::render(Console& console) {
	std::string line;
	std::ifstream nameFile("ASCIIArt\\startMenu.txt");
	int linecount = 0;

	if (nameFile.is_open()) {
		while (std::getline(nameFile, line)) {
			console.writeToBuffer(12, 2 + linecount, line, FG_RED + BG_WHITE);
			linecount++;
		}
		nameFile.close();
	}
	linecount = 0;

	std::ifstream startButtonFile("ASCIIArt\\startButton.txt");

	if (currentSelection == 1) {
		if (startButtonFile.is_open()) {
			while (std::getline(startButtonFile, line)) {
				console.writeToBuffer(15, 16 + linecount, line, FG_RED);
				linecount++;
			}
			startButtonFile.close();
		}
		console.writeToBuffer(37,23, "EXIT", FG_WHITE);
	}

	
	if (currentSelection == 2) {
		if (startButtonFile.is_open()) {
			while (std::getline(startButtonFile, line)) {
				console.writeToBuffer(15, 16 + linecount, line, FG_WHITE);
				linecount++;
			}
			startButtonFile.close();
		}
		console.writeToBuffer(37,23, "EXIT", FG_RED);
	}
	
}