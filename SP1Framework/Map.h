#include "Framework/console.h"
#include "Player.h"
#include "colors.h"
#pragma once

enum MapElements {
	EMPTY = ' ',
	FLOOR = 178,
};

class Map
{
private:
	int length;
	int height;

	char** mapArray;

public:
	//Constructor/Destructor
	Map();
	Map(int height, int length);
	~Map();

	//Renders map to console
	void renderMap(Console& console);
	void renderMap(Console& console, Player& player);

	//Get map object
	char getMap(int x, int y);
};

