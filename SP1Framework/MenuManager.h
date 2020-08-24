#pragma once
#include "game.h"
#include "gameState.h"
#include "Framework/console.h"
#include "colors.h"

#include <fstream>

class MenuManager
{
private:
	int currentSelection;

	void renderStartMenu(Console& console);
	void renderPauseMenu(Console& console);

	void updateStartMenu(int& gameState, SKeyEvent KeyEvent[K_COUNT]);

	void updateLevelSelectMenu(int& gameState, SKeyEvent KeyEvent[K_COUNT], int& currStage, int& currLevel);

public:
	MenuManager();
	~MenuManager();

	void update(int& gameState, SKeyEvent KeyEvent[K_COUNT], int& currStage, int& currLevel);
	void render(int& gameState, Console& console);

};

