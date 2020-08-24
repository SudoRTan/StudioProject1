#include "PauseMenu.h"


PauseMenu::PauseMenu() {
	currentSelection = 0;
	totalSelections = 0;
}

PauseMenu::~PauseMenu() {

}

void PauseMenu::update(int& gameState, SKeyEvent KeyEvent[K_COUNT], int& currStage, int& currLevel) {

}



void PauseMenu::render(Console& console) {
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
