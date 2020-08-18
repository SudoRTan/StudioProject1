#pragma once
#include "Framework/console.h"
#include "colors.h"

enum MapElements {
	INVALID = 0,
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
	char getItem(int x, int y);

	//Set map object
	void setItem(int x, int y, char symbol);

	//Read map stage from .txt file
	void loadMap(std::string filename, Console& console);
};

