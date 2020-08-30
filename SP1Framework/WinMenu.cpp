#include "WinMenu.h"

WinMenu::WinMenu() {
	currentSelection = 1;
	totalSelections = 1;
}

WinMenu::~WinMenu() {


}

void WinMenu::update(int& gameState, SKeyEvent KeyEvent[K_COUNT], int& currStage, int& currLevel, int unlockedStage, int unlockedLevel) {
	if (KeyEvent[K_SPACE].keyOnce) {
		if (currentSelection == 1) {
			gameState = FINISHED_LEVEL;
			PlaySound(TEXT("./Sounds/menuConfirm.wav"), NULL, SND_FILENAME | SND_ASYNC);
		}
	}
	else if (KeyEvent[K_ESCAPE].keyOnce) {
		gameState = FINISHED_LEVEL;
		PlaySound(TEXT("./Sounds/menuEscape.wav"), NULL, SND_FILENAME | SND_ASYNC);

	}
}


void WinMenu::render(Console& console) {
	std::string line;
	std::ifstream winFile("ASCIIArt\\winMenu.txt");
	int linecount = 0;

	if (winFile.is_open()) {
		while (std::getline(winFile, line)) {
			console.writeToBuffer(12, 2 + linecount, line, FG_RED + BG_WHITE);
			linecount++;
		}
		winFile.close();
	}

	std::ifstream file("ASCIIArt\\humanitySaved.txt");
	linecount = 0;


	if (file.is_open()) {
		while (std::getline(file, line)) {
			console.writeToBuffer(13, 10 + linecount, line, FG_RED + BG_WHITE);
			linecount++;
		}
		file.close();
	}
	
	console.writeToBuffer(22, 24, "Press space to return to start menu", FG_RED + BG_WHITE);




}