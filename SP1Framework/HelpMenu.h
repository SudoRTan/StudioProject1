#pragma once
#include "Menu.h"
class HelpMenu :
	public Menu
{

public:
	HelpMenu();
	~HelpMenu();

	void update(int& gameState, SKeyEvent KeyEvent[K_COUNT], int& currStage, int& currLevel, int unlockedStage, int unlockedLevel);

	void render(Console& console);
};
