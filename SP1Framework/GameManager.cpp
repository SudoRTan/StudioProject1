#include "GameManager.h"


GameManager::GameManager(){

	currStage = 1;
	currLevel = 1;

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

void GameManager::update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime) {
	
	
	gameTime = g_dElapsedTime - timeEnlapsedSincePause;


	switch (currGameState) {
	case IN_LEVEL:
		stage->update(KeyEvent, gameTime,  currGameState);
		break;

	case FINISHED_LEVEL:
		if (currLevel == 4) {
			currLevel = 1;
			currStage++;
		}
		currLevel++;
		//stage->loadMap("stage" + std::to_string(currStage) + "_" + std::to_string(currLevel) + ".txt");
		loadStage();
		currGameState = IN_LEVEL;
		break;
	
	case RESUME_LEVEL:
		currGameState = IN_LEVEL;
		timeEnlapsedSincePause = g_dElapsedTime - pauseTime;
		break;

	case RELOAD_LEVEL:
		player->resetHealth();

	case LOAD_LEVEL:
		loadStage();
		currGameState = IN_LEVEL;
		break;


	case START_MENU:
		player->resetHealth();
	default:
		menu.update(currGameState, KeyEvent, currStage, currLevel);
		break;
	}

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

	case FINISHED_LEVEL:
	case LOAD_LEVEL:
	case RELOAD_LEVEL:
	case RESUME_LEVEL:
		break;

	case PLAYER_DEATH:
	default:
		menu.render(currGameState, console);
		break;
	}
	
}

void GameManager::loadStage() {
	std::stringstream ss;

	
	ss << "stage" << currStage << "_" << currLevel << ".txt";

	std::string test = ss.str();
	
	if (currLevel == 4) {
		if (stage == nullptr) {
			stage = new BossStage1(player);
		}
		else {
			delete stage;
			stage = new BossStage1(player);
		}
	}
	else {
		if (stage == nullptr) {
			stage = new Stage(player);
		}
		else {
			delete stage;
			stage = new Stage(player);
		}
	}
	stage->loadMap(ss.str());
	
}