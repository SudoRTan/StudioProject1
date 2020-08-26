#pragma once
#include "game.h"
#include "gameState.h"
#include <iostream>
#include "Framework/console.h"
#include "MenuManager.h"
#include <sstream>

#include "Stage.h"
#include "BossStage1.h"

class GameManager
{
private:
	MenuManager menu;

	Player* player;
	Stage* stage;


	int currGameState;
	
	int currStage;
	int currLevel;

	double gameTime;
	double pauseTime;
	double timeEnlapsedSincePause;
	

public:
	GameManager();
	~GameManager(); 


	void update(SKeyEvent KeyEvent[K_COUNT], double enlapsedTime);
	void render(Console& console);

	void loadStage(double enlapsedTime);
};

