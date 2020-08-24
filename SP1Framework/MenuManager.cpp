#include "MenuManager.h"



MenuManager::MenuManager() {
}

MenuManager::~MenuManager() {

}

void MenuManager::update(int& gameState, SKeyEvent KeyEvent[K_COUNT], int& currStage, int& currLevel) {
	switch (gameState) {
	case START_MENU:
		updateStartMenu(gameState, KeyEvent);
		break;

	case LEVEL_SELECT:
		updateLevelSelectMenu(gameState, KeyEvent, currStage, currLevel);

	default:
		break;
	}
}

void MenuManager::render(int& gameState, Console& console) {
	switch (gameState) {
	case PAUSE_MENU:
		renderPauseMenu(console);
		break;
	case START_MENU:
		renderStartMenu(console);
		break;
	default:
		break;
	}
}

void MenuManager::renderStartMenu(Console& console) {
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

void MenuManager::renderPauseMenu(Console& console) {

	std::string line;
	std::ifstream pauseText("pauseButton.txt");
	int linecount = 0;

	if (pauseText.is_open()) {
		while (std::getline(pauseText, line)) {
			console.writeToBuffer(9, 5 + linecount, line, FG_BLUE);
			linecount++;
		}
		pauseText.close();
	}

}

void MenuManager::updateStartMenu(int& gameState, SKeyEvent KeyEvent[K_COUNT]) {
	if (KeyEvent[K_SPACE].keyOnce) {
		gameState = LEVEL_SELECT;
	}
}

void MenuManager::updateLevelSelectMenu(int& gameState, SKeyEvent KeyEvent[K_COUNT], int& currStage, int& currLevel) {
	if (currStage == 0) {

	}

	else {

	}
}