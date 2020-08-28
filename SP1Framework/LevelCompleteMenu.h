#pragma once
#include "Menu.h"
class LevelCompleteMenu :
	public Menu
{
public:
	LevelCompleteMenu();
	~LevelCompleteMenu();

	void update(int& gameState, SKeyEvent KeyEvent[K_COUNT], int& currStage, int& currLevel, int unlockedStage, int unlockedLevel);
	void render(Console& console);
};

