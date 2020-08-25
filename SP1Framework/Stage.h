#pragma once
#include "Map.h"
#include "Enemy.h"
#include "EnemyTemplate.h"
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
	std::string currentStage;

	std::string type;

	void cleanUp(void);

	EntityManager entityManager;


public:
	Stage(Player* player);
	virtual ~Stage();

	std::string getStage(void);


	void loadMap(std::string fileName);

	virtual void update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, int& gameState);

	void render(Console& console);

	std::string getType();


};


