#include "GameManager.h"


GameManager::GameManager(){

	currStage = 1;
	currLevel = 1;

	unlockedStage = 7;
	unlockedLevel = 1;

	pauseTime = 0.0;
	timeEnlapsedSincePause = 0.0;
	gameTime = 0.0;

	currGameState = START_MENU;

	player = new Player;

	stage = nullptr;
}


GameManager::~GameManager() {
	delete stage;
	stage = nullptr;

	delete player;
	player = nullptr;
}

void GameManager::update(SKeyEvent KeyEvent[K_COUNT], double enlapsedTime, bool& quitGame) {
	
	
	gameTime = enlapsedTime - timeEnlapsedSincePause;


	switch (currGameState) {
	case IN_LEVEL:
		stage->update(KeyEvent, gameTime,  currGameState);
		break;

	case NEXT_LEVEL:
		if (currLevel == 4) {
			currLevel = 1;
			currStage++;
		}
		else {
			currLevel++;
		}
		currGameState = LOAD_LEVEL;
		break;
	
	case RESUME_LEVEL:
		currGameState = IN_LEVEL;
		timeEnlapsedSincePause = enlapsedTime - pauseTime;
		break;

	case RELOAD_LEVEL:
		player->resetHealth();

	case LOAD_LEVEL:
		player->resetHealth();
		player->resetWeapon();
		loadStage(enlapsedTime);
		currGameState = IN_LEVEL;
		break;

	case FINISHED_LEVEL:
		if (currStage == 6 && currLevel == 4) {
			currGameState = START_MENU;
		}
		else if (currLevel == 4 && unlockedStage == currStage) {
			unlockedStage++;
			unlockedLevel = 1;
			currGameState = LEVEL_COMPLETE_MENU;
		}
		else if (unlockedStage == currStage && unlockedLevel == currLevel) {
			unlockedLevel++;
			currGameState = LEVEL_COMPLETE_MENU;
		}
		else {
			currGameState = LEVEL_COMPLETE_MENU;
		}
		break;

	case EXIT_GAME:
		g_bQuitGame = true;
		break;

	case START_MENU:
		player->resetHealth();
	default:
		menu.update(currGameState, KeyEvent, currStage, currLevel, unlockedStage, unlockedLevel);
		break;
	}

	// Enters the pause menu if esc key is pressed when in level
	if (KeyEvent[K_ESCAPE].keyOnce) {
		switch (currGameState) {
		case IN_LEVEL:
			currGameState = PAUSE_MENU;
			pauseTime = gameTime;
			break;

		default:
			break;
		}
	}

}	

void GameManager::render(Console& console) {
	switch (currGameState) {
	case IN_LEVEL:
		stage->render(console);
		break;

	case START_MENU:
	case PAUSE_MENU:
	case LEVEL_SELECT:
	case PLAYER_DEATH:
	case LEVEL_COMPLETE_MENU:
	case HELP_MENU:
		menu.render(currGameState, console);
		break;

	case NEXT_LEVEL:
	case LOAD_LEVEL:
	case RELOAD_LEVEL:
	case RESUME_LEVEL:
	default:
		break;
	}
	
}

void GameManager::loadStage(double enlapsedTime) {
	//If selected stage is a boss stage
	if (currLevel == 4) {
		if (stage != nullptr) {
			delete stage;
		}

		switch (currStage) {
		case 1:
			stage = new BossStage1(player, enlapsedTime);
			break;

		case 2:
			stage = new BossStage2(player);
			break;

		case 3:
			stage = new BossStage3(player);
			break;

		case 4:
			stage = new BossStage4(player);
			break;

		case 5:
			stage = new BossStage5(player);
			break;

		case 6:
			//stage = new BossStage6(player);
			break;

		default:
			break;
		}
		
	}
	// If selected stage is a normal stage
	else {
		if (stage == nullptr) {
			stage = new Stage(player);
		}
		else {
			delete stage;
			stage = new Stage(player);
		}
	}
	stage->loadMap(currStage, currLevel);
	
}