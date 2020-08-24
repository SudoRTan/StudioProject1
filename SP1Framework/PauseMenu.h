#pragma once
#include "Menu.h"
class PauseMenu :
	public Menu
{

public:
	PauseMenu();
	~PauseMenu();

	void update(int& gameState, SKeyEvent KeyEvent[K_COUNT], int& currStage, int& currLevel);

	void render(Console& console);
};

