#pragma once
#include "game.h"
#include "gameState.h"
#include <iostream>
#include "Framework/console.h"
#include "MenuManager.h"
#include <sstream>

#include "Stage.h"
#include "BossStage1.h"
#include "BossStage2.h"
#include "BossStage3.h"
#include "BossStage4.h"
#include "BossStage5.h"
#include "BossStage6.h"

class GameManager
{
private:
	MenuManager menu;

	Player* player;
	Stage* stage;


	int currGameState;

	//Variables to store user current stage
	int currStage;
	int currLevel;

	// Variables to store user unlocked stage
	int unlockedStage;
	int unlockedLevel;


	double gameTime;
	double pauseTime;
	double timeEnlapsedSincePause;


public:
	GameManager();
	~GameManager(); 


	void update(SKeyEvent KeyEvent[K_COUNT], double enlapsedTime, bool& quitGame);
	void render(Console& console);

	void loadStage(double enlapsedTime);
};

