#pragma once
#include "Menu.h"
class WinMenu :
	public Menu
{

private:

public:

	WinMenu();
	~WinMenu();

	void update(int& gameState, SKeyEvent KeyEvent[K_COUNT], int& currStage, int& currLevel, int unlockedStage, int unlockedLevel);
	void render(Console& console);

};

