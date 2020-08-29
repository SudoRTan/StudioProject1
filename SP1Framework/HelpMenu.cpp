#include "HelpMenu.h"


HelpMenu::HelpMenu() {
}

HelpMenu::~HelpMenu() {
	
}

void HelpMenu::update(int& gameState, SKeyEvent KeyEvent[K_COUNT], int& currStage, int& currLevel, int unlockedStage, int unlockedLevel) {
	 if (KeyEvent[K_ESCAPE].keyOnce) {
		gameState = PAUSE_MENU;
		PlaySound(TEXT("./Sounds/menuEscape.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}
}

void HelpMenu::render(Console& console)
{
	std::string boxLine;
	std::ifstream boxFile("./ASCIIArt/helpMenuText.txt");
	int boxLinecount = 0;

	if (boxFile.is_open()) {
		while (std::getline(boxFile, boxLine)) {
			console.writeToBuffer(4, 12 + boxLinecount, boxLine, FG_RED + BG_WHITE);
			boxLinecount++;
		}
		boxFile.close();
	}
	boxLinecount = 0;

	std::string   HelpMenuLine;
	std::ifstream HelpMenuFile("HelpMenu.txt");
	int HelpMenuLineCount = 0;

	
	if (HelpMenuFile.is_open()) {
		while (std::getline(HelpMenuFile, HelpMenuLine)) {
			console.writeToBuffer(8, 1 + HelpMenuLineCount, HelpMenuLine, FG_RED + BG_WHITE);
			HelpMenuLineCount++;
		}
		HelpMenuFile.close();
	}
	HelpMenuLineCount = 0;

}
