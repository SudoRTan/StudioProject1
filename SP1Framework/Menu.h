#pragma once
#include "game.h"
#include "gameState.h"
#include "Framework/console.h"
#include "colors.h"
#include <fstream>


class Menu
{

protected:
	int currentSelection;
	int totalSelections;

public:
	virtual void update(int& gameState, SKeyEvent KeyEvent[K_COUNT], int& currStage, int& currLevel) = 0;

	virtual void render(Console& console) = 0;
};

