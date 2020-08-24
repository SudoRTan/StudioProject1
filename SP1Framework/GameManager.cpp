#include "GameManager.h"


GameManager::GameManager(){

	currStage = 1;
	currLevel = 1;

	currGameState = IN_LEVEL;
	stage.loadMap(stage.getStage());

}


GameManager::~GameManager() {
}

void GameManager::update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime) {
	
	if (KeyEvent[K_ESCAPE].keyOnce) {
		if (currLevel == 3) {
			currLevel = 1;
			currStage++;
		}
		currLevel++;

		stage.loadMap("stage" + std::to_string(currStage) + "_" + std::to_string(currLevel) + ".txt");
	}
	else {
		stage.update(KeyEvent, g_dElapsedTime);
	}
	
}

void GameManager::render(Console& console) {
	stage.render(console);
}