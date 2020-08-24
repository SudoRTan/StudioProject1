#include "GameManager.h"


GameManager::GameManager(){

	currStage = 1;
	currLevel = 1;

	pauseTime = 0.0;

	currGameState = IN_LEVEL;
	stage.loadMap(stage.getStage());

}


GameManager::~GameManager() {
}

void GameManager::update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime) {
	
	if (KeyEvent[K_ESCAPE].keyOnce) {
		switch (currGameState) {
		case PAUSE_MENU:
			currGameState = IN_LEVEL;
			timeEnlapsedSincePause = g_dElapsedTime - pauseTime;
			break;

		case IN_LEVEL:
			currGameState = PAUSE_MENU;
			pauseTime = gameTime;
			break;

		default: 
			break;
		}
	}

	gameTime = g_dElapsedTime - timeEnlapsedSincePause;


	switch (currGameState) {
	case IN_LEVEL:
		stage.update(KeyEvent, gameTime, currGameState);
		break;

	case PAUSE_MENU:
		break;

	case FINISHED_LEVEL:
		if (currLevel == 3) {
			currLevel = 1;
			currStage++;
		}
		currLevel++;
		stage.loadMap("stage" + std::to_string(currStage) + "_" + std::to_string(currLevel) + ".txt");
		currGameState = IN_LEVEL;
		break;

	default:
		break;
	}
}

void GameManager::render(Console& console) {
	switch (currGameState) {
	case IN_LEVEL:
		stage.render(console);
		break;

	case PAUSE_MENU:
		renderPauseMenu(console);
		break;


	case FINISHED_LEVEL:

	default:
		break;
	}
	
}

void GameManager::renderPauseMenu(Console& console) {

	std::string line;
	std::ifstream pauseText("pauseButton.txt");
	int linecount = 0;

	if (pauseText.is_open()) {
		while (std::getline(pauseText, line)) {
			console.writeToBuffer(9, 5 + linecount, line, FG_BLUE);
			linecount++;
		}
		pauseText.close();
	}

}