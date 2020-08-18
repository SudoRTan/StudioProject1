#pragma once
#include "Framework/console.h"
#include "colors.h"

enum MapElements {
	EMPTY = ' ',
	FLOOR = 178,
	PLATFORM = 205,
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
	void renderMap(Console& console, int x, int y);

	//Get map object
	char getMap(int x, int y);

	//Read map stage from .txt file
	void LoadMap(std::string filename, Console& console);
};

