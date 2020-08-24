#pragma once
#include "Stage.h"
#include "game.h"
#include "gameState.h"
#include <iostream>
#include <fstream>



class GameManager
{
private:
	Stage stage;
	int currGameState;
	
	int currStage;
	int currLevel;

	double gameTime;
	double pauseTime;
	double timeEnlapsedSincePause;
	

public:
	GameManager();
	~GameManager(); 


	void update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime);
	void render(Console& console);

	void renderPauseMenu(Console& console);
};

