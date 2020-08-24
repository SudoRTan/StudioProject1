#pragma once
#include "Stage.h"
#include "game.h"

enum GAMESTATE {
	IN_LEVEL,
	PAUSE_MENU,
	START_MENU,
	LEVEL_SELECT
};


class GameManager
{
private:
	Stage stage;
	int currGameState;
	
	int currStage;
	int currLevel;

	

public:
	GameManager();
	~GameManager();


	void update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime);
	void render(Console& console);
};

