﻿#pragma once
#include "Framework/console.h"
#include "colors.h"
#include "Position.h"
#include <fstream>
#include <sstream>
#include "createArray.h"
#include "EntityTemplate.h"

enum MAP_ELEMENTS {
	INVALID = 0,
	EMPTY = ' ',
	DOOR = 68,
	SPIKE = 94,
	LAVA = 95,
	FLOOR = 61,
	WALL = 124,
	PLATFORM = 45,
};

enum ENEMY_TYPES {
	ENEMY_1 = 49,
	ENEMY_2 = 50,
	ENEMY_3 = 51
};


enum COLLECTIBLE_TYPES {
	HEALTH = 'H',
	AMMO = 'A',
	SWORD = 'S',
	GUN = 'G'
};

class Map
{
private:
	int length;
	int height;

	char** mapArray;
	char** mapTemplate;

	char** tempMapArray;


	//Used to store locations / number of enemies;
	int numberOfEnemies;

	EntityTemplate** enemyTemplate;

	int numberOfCollectible;
	EntityTemplate** collectibleTemplate;

	COORD playerStartingPos;

	int currStage;

	int currLevel;



public:
	//Constructor/Destructor
	Map();
	Map(int currStage, int currLevel);
	~Map();


	//Renders map to console
	void renderMap(Console& console);
	void renderMap(Console& console, int x, int y);

	//Get map object
	char getItem(int x, int y);

	//Set map object
	void setItem(int x, int y, char symbol);


	char getDefaultItem(int x, int y);
	void setDefaultItem(int x, int y);
	
	void setTempItem(int x, int y, char symbol);

	int getNumberOfEnemies();


	COORD getPlayerPosition();

	EntityTemplate** getEnemyTemplate();


	int getNumberOfCollectibles();
	EntityTemplate** getCollectibleTemplate();


};

