#include "Map.h"

Map::Map() {
	height = 16;
	length = 80;

	mapArray = new char* [height];
	for (int i = 0; i < height; i++) {
		mapArray[i] = new char[length];
	}


	for (int i = 0; i < height; i++) {
		for (int j = 0; j < length; j++) {
			mapArray[i][j] = ' ';
		}
	}
	for (int i = 0; i < length; i++) {
		mapArray[0][i] = (char)FLOOR;
	}
}

Map::Map(int height, int length) {
	this->height = height;
	this->length = length;

	mapArray = new char* [height];
	for (int i = 0; i < height; i++) {
		mapArray[i] = new char[length];
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < length; j++) {
			mapArray[i][j] = ' ';
		}
	}
	for (int i = 0; i < length; i++) {
		if (i % 2 == 0) {
			mapArray[0][i] = (char)FLOOR;
		}
		else {
			mapArray[0][i] = (char)FLOOR + 1;
		}
	}
}



Map::~Map() {
	for (int i = 0; i < height; i++) {
		delete[] mapArray[i];
	}
	delete[] mapArray;

}

void Map::renderMap(Console& console) {
	const int yOffset = 9;

	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 80; j++) {
			console.writeToBuffer(j, 24-i, mapArray[i][j],BG_CYAN+FG_LIGHTMAGENTA);
		}
	}
}

void Map::renderMap(Console& console, Player& player) {
	int playerX = player.getPositionX();
	int playerY = player.getPositionY();

	//16x80

	
	int mapOffsetX = playerX - 80 / 2;
	int mapOffsetY = playerY - 16 / 2;
	
	if (mapOffsetX < 0) {
		mapOffsetX = 0;
	}
	if (mapOffsetY < 0) {
		mapOffsetY = 0;
	}
	if (mapOffsetX + 80 > length) {
		mapOffsetX = length-80;
	}

	console.writeToBuffer(0, 4, (char)48 + playerX, FG_BLACK + BG_WHITE);
	console.writeToBuffer(0, 5, (char)48 + playerY, FG_BLACK + BG_WHITE);
	console.writeToBuffer(0, 6, (char)48+mapOffsetX, FG_BLACK + BG_WHITE);
	console.writeToBuffer(0, 7, (char)48+mapOffsetY, FG_BLACK + BG_WHITE);

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < length; j++) {
			console.writeToBuffer(j, 24 - i, mapArray[i + mapOffsetY][j + mapOffsetX], BG_CYAN + FG_LIGHTMAGENTA);
		}
	}
}


char Map::getMap(int x, int y) {
	// Gets the map character from a specifc position
	return mapArray[x][y];		
}

