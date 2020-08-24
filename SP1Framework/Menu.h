#pragma once
#include "game.h"
#include "gameState.h"
#include "Framework/console.h"
#include "colors.h"

#include <fstream>

class Menu
{
private:
	int currentSelection;


	void renderPauseMenu(Console& console);

public:
	Menu();
	~Menu();

	void update(int gameState, SKeyEvent KeyEvent[K_COUNT]);
	void render(int gameState, Console& console);

};

