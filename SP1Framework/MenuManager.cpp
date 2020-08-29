#include "MenuManager.h"



MenuManager::MenuManager() {
	menus = new Menu * [TOTAL_EVENTS];
	for (int i = 0; i < TOTAL_EVENTS; i++) {
		menus[i] = nullptr;
	}

	menus[START_MENU] = new StartMenu;
	menus[PAUSE_MENU] = new PauseMenu;
	menus[LEVEL_SELECT] = new LevelSelectMenu;
	menus[PLAYER_DEATH] = new DeathMenu;
	menus[LEVEL_COMPLETE_MENU] = new LevelCompleteMenu;
	menus[HELP_MENU] = new HelpMenu;
}

MenuManager::~MenuManager() {
	for (int i = 0; i < TOTAL_EVENTS; i++) {
		if (menus[i] != nullptr) {
			delete menus[i];
		}
	}

	delete[] menus;
}

void MenuManager::update(int& gameState, SKeyEvent KeyEvent[K_COUNT], int& currStage, int& currLevel, int unlockedStage, int unlockedLevel) {
	menus[gameState]->update(gameState, KeyEvent, currStage, currLevel, unlockedStage, unlockedLevel);

}

void MenuManager::render(int& gameState, Console& console) {
	menus[gameState]->render(console);

}



/*

void MenuManager::updateLevelSelectMenu(int& gameState, SKeyEvent KeyEvent[K_COUNT], int& currStage, int& currLevel) {
	if (currStage == 0) {

	}

	else {

	}
}
*/