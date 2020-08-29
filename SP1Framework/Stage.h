#pragma once
#include "Map.h"
#include "Enemy.h"
#include "EntityTemplate.h"
#include "Player.h"
#include "game.h"
#include "UI.h"
#include "Framework/console.h"
#include "gameState.h"
#include "EntityManager.h"


class Stage
{
protected:
	Map* map;
	Player* player;
	int numOfEnemies;
	int stageNumber;
	int levelNumber;
	UI ui;

	std::string type;

	void cleanUp(void);

	EntityManager entityManager;


public:
	Stage(Player* player);
	virtual ~Stage();

	std::string getStage(void);


	void loadMap(int stageToLoad, int levelToLoad);

	virtual void update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, int& gameState);

	void render(Console& console);

	std::string getType();


};


