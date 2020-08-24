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

class MenuManager
{
private:

	Menu** menus;

	void renderPauseMenu(Console& console);


	void updateLevelSelectMenu(int& gameState, SKeyEvent KeyEvent[K_COUNT], int& currStage, int& currLevel);

public:
	MenuManager();
	~MenuManager();

	void update(int& gameState, SKeyEvent KeyEvent[K_COUNT], int& currStage, int& currLevel);
	void render(int& gameState, Console& console);

};

