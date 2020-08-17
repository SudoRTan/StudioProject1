#include "Map.h"

Map::Map() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 80; j++) {
			mapArray[i][j] = ' ';
		}
	}
	for (int i = 0; i < 80; i++) {
		mapArray[15][i] = (char)FLOOR;
	}
}

Map::~Map() {

}

void Map::renderMap(Console& console) {
	const int yOffset = 9;

	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 80; j++) {
			console.writeToBuffer(j, i + yOffset, mapArray[i][j],BG_CYAN+FG_LIGHTMAGENTA);
		}
	}
}

char Map::getMap(int x, int y) {
	// Gets the map character from a specifc position
	return mapArray[x][y];		
}

