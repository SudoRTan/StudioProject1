#pragma once
#include "Menu.h"
class DeathMenu :
	public Menu
{
private:

public:
	DeathMenu();
	~DeathMenu();

	void update(int& gameState, SKeyEvent KeyEvent[K_COUNT], int& currStage, int& currLevel);

	void render(Console& console);
};

