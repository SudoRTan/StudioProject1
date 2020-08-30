#pragma once
#include "Menu.h"
class AprilFoolsMenu :
	public Menu
{
private:

public:
	AprilFoolsMenu();

	~AprilFoolsMenu();

	void render(Console& console);

	void update(int& gameState, SKeyEvent KeyEvent[K_COUNT], int& currStage, int& currLevel, int unlockedStage, int unlockedLevel);

};

