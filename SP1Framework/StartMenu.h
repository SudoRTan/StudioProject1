#pragma once
#include "Menu.h"

class StartMenu:
	public Menu
{
public:
	StartMenu();
	~StartMenu();

	void update(int& gameState, SKeyEvent KeyEvent[K_COUNT], int& currStage, int& currLevel);

	void render(Console& console);
};

