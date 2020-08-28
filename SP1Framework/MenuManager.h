#pragma once
#include "game.h"
#include "gameState.h"
#include "Framework/console.h"
#include "colors.h"
#include <fstream>

#include "Menu.h"
#include "StartMenu.h"
#include "PauseMenu.h"
#include "LevelSelectMenu.h"
#include "DeathMenu.h"
#include "LevelCompleteMenu.h"

class MenuManager
{
private:

	Menu** menus;

	void renderPauseMenu(Console& console);


	void updateLevelSelectMenu(int& gameState, SKeyEvent KeyEvent[K_COUNT], int& currStage, int& currLevel);

public:
	MenuManager();
	~MenuManager();

	void update(int& gameState, SKeyEvent KeyEvent[K_COUNT], int& currStage, int& currLevel, int unlockedStage, int unlockedLevel);
	void render(int& gameState, Console& console);

};

