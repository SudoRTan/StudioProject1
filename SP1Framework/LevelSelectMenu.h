#pragma once
#include "Menu.h"
class LevelSelectMenu :
	public Menu
{
private:
	int totalStage;
	int highLightedStage;

	int selectedStage;


public:
	LevelSelectMenu();
	~LevelSelectMenu();

	void update(int& gameState, SKeyEvent KeyEvent[K_COUNT], int& currStage, int& currLevel, int unlockedStage, int unlockedLevel);

	void render(Console& console);
};

