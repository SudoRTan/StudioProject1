#include "Framework/console.h"
#include "colors.h"
#pragma once

enum MapElements {
	EMPTY = ' ',
	FLOOR = 178,
};

class Map
{
private:
	char mapArray[16][80];

public:
	//Constructor/Destructor
	Map();
	~Map();

	//Renders map to console
	void renderMap(Console& console);

	//Get map object
	char getMap(int x, int y);
};

