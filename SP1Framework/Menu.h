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

	void increaseSelection();
	void decreaseSelection();

public:

	//Constructors and destructors
	Menu();
	~Menu();

	// Pure virtual functions
	virtual void update(int& gameState, SKeyEvent KeyEvent[K_COUNT], int& currStage, int& currLevel) = 0;

	virtual void render(Console& console) = 0;
};

