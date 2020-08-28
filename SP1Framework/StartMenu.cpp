#include "StartMenu.h"

StartMenu::StartMenu() {
	currentSelection = 1;
	totalSelections = 1;
}

StartMenu::~StartMenu() {

}

void StartMenu::update(int& gameState, SKeyEvent KeyEvent[K_COUNT], int& currStage, int& currLevel) {
	if (KeyEvent[K_SPACE].keyOnce) {
		gameState = LEVEL_SELECT;
		PlaySound(TEXT("./Sounds/menuConfirm.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}
}

void StartMenu::render(Console& console) {
	std::string line;
	std::ifstream nameFile("startMenu.txt");
	int linecount = 0;

	if (nameFile.is_open()) {
		while (std::getline(nameFile, line)) {
			console.writeToBuffer(12, 2 + linecount, line, FG_RED + BG_WHITE);
			linecount++;
		}
		nameFile.close();
	}
	linecount = 0;

	std::ifstream startButtonFile("startButton.txt");

	if (startButtonFile.is_open()) {
		while (std::getline(startButtonFile, line)) {
			console.writeToBuffer(15, 16 + linecount, line);
			linecount++;
		}
		startButtonFile.close();
	}
}