#pragma once
#include "Stage.h"
#include "game.h"
#include "gameState.h"
#include <iostream>
#include "Framework/console.h"
#include "Menu.h"


class GameManager
{
private:
	Stage stage;
	Menu menu;


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


};

