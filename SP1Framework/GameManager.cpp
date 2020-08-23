#include "GameManager.h"


GameManager::GameManager(){
	currGameState = IN_LEVEL;
	stage.loadMap(stage.getStage());
}


GameManager::~GameManager() {
}

void GameManager::update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime) {
	stage.update(KeyEvent, g_dElapsedTime);
}

void GameManager::render(Console& console) {
	stage.render(console);
}