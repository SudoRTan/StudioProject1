#include "Map.h"

int getSmaller(int first, int second) {
	if (first > second)
		return second;
	else
		return first;
}




Map::Map()
{
	height = 16;
	length = 80;

	playerStartingPos.X = 0;
	playerStartingPos.Y = 1;

	// Sets default values for mapArrays
	numberOfEnemies = 0;
	numberOfCollectible = 0;

	enemyTemplate = nullptr;
	collectibleTemplate = nullptr;

	mapArray = nullptr;
	mapTemplate = nullptr;

	tempMapArray = nullptr;

	currStage = 1;

	currLevel = 1;

	mapArray = new char* [height];
	for (int i = 0; i < height; i++)
	{
		mapArray[i] = new char[length];
	}

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < length; j++)
		{
			mapArray[i][j] = ' ';
		}
	}
	for (int i = 0; i < length; i++)
	{
		mapArray[0][i] = (char)FLOOR;
	}

}



Map::Map(int currStage, int currLevel)
{
	height = 0;
	length = 0;

	playerStartingPos.X = 0;
	playerStartingPos.Y = 1;


	// Sets default values for mapArrays
	numberOfEnemies = 0;
	numberOfCollectible = 0;

	enemyTemplate = nullptr;
	collectibleTemplate = nullptr;

	mapArray = nullptr;
	mapTemplate = nullptr;

	tempMapArray = nullptr;


	this->currStage = currStage;

	this->currLevel = currLevel;

	std::stringstream ss;

	ss << "Levels\\stage" << currStage << "_" << currLevel << ".txt";


	std::string line = "";
	int lines = 0;
	int columns = 0;

	std::ifstream file(ss.str());

	if (file.is_open()) {
		while (!file.eof()) {
			getline(file, line);
			int lengthOfLine = size(line);

			if (lengthOfLine > columns) {
				columns = lengthOfLine;
			}

			lines++;
		}

		file.clear();
		file.seekg(0, std::ios::beg);

		height = lines;
		length = columns;

		mapArray = createArray(columns, lines);
		mapTemplate = createArray(columns, lines);
		tempMapArray = createArray(columns, lines);


		int readingLine = height-1;
		while (!file.eof()) {
			getline(file, line);
			int lengthOfLine = size(line);

			for (int i = 0; i < lengthOfLine; i++) {
				mapArray[readingLine][i] = line[i];
				mapTemplate[readingLine][i] = line[i];

				//Checks all the elements in the map
				switch (mapArray[readingLine][i]) {
					//If the item is an Enemy
				case 'E':
				case '1':
				case '2':
				case '3':
					numberOfEnemies++;
					break;

					//If the item is a collectible
				case HEALTH:
				case AMMO:
				case SWORD:
				case GUN:
					numberOfCollectible++;
					break;

				default:
					break;
				}

			}
			readingLine--;
		}

		// Creates array to store starting location of Enemies;

		enemyTemplate = new EntityTemplate * [numberOfEnemies];

		for (int i = 0; i < numberOfEnemies; i++) {
			enemyTemplate[i] = new EntityTemplate;
			
			enemyTemplate[i]->postion.X = 0;
			enemyTemplate[i]->postion.Y = 0;
			enemyTemplate[i]->symbol = ' ';
			
		}

		collectibleTemplate = new EntityTemplate * [numberOfCollectible];

		for (int i = 0; i < numberOfCollectible; i++) {
			collectibleTemplate[i] = new EntityTemplate;

			collectibleTemplate[i]->postion.X = 0;
			collectibleTemplate[i]->postion.Y = 0;
			collectibleTemplate[i]->symbol = ' ';

		}

		


		int enemyCounter = 0;
		int collectibleCounter = 0;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < length; j++) {
				switch (mapArray[i][j]) {
					// PLayer is at location
				case 'P':
					playerStartingPos.X = j;
					playerStartingPos.Y = i;
					mapArray[i][j] = EMPTY;
					mapTemplate[i][j] = EMPTY;
					break;

					//Enenmy is at location
				case 'E':
				case '1':
				case '2':
				case '3':
					enemyTemplate[enemyCounter]->postion.X = j;
					enemyTemplate[enemyCounter]->postion.Y = i;
					enemyTemplate[enemyCounter]->symbol = mapArray[i][j];
					enemyCounter++;
					mapArray[i][j] = EMPTY;
					mapTemplate[i][j] = EMPTY;
					break;

					//Collectible is at location
				case HEALTH:
				case AMMO:
				case SWORD:
				case GUN:
					collectibleTemplate[collectibleCounter]->postion.X = j;
					collectibleTemplate[collectibleCounter]->postion.Y = i;
					collectibleTemplate[collectibleCounter]->symbol = mapArray[i][j];
					mapArray[i][j] = EMPTY;
					mapTemplate[i][j] = EMPTY;
					collectibleCounter++;
					break;

				default:
					break;
				}
				tempMapArray[i][j] = mapArray[i][j];
			}
		}
		file.close();

	}

	
}

Map::~Map()
{
	// deletes values in map arrays when level is complete and default destructor is called
	if (mapArray != nullptr) {
		for (int i = 0; i < height; i++)
		{
			delete[] mapArray[i];
			delete[] mapTemplate[i];
			delete[] tempMapArray[i];
		}
		delete[] mapArray;
		delete[] mapTemplate;
		delete[] tempMapArray;
		mapArray = nullptr;
		mapTemplate = nullptr;
		tempMapArray = nullptr;

	}
	
	if (enemyTemplate != nullptr) {
		for (int i = 0; i < numberOfEnemies; i++) {
			if (enemyTemplate[i] != nullptr) {
				delete enemyTemplate[i];
				enemyTemplate[i] = nullptr;

			}
		}

		delete[] enemyTemplate;
		enemyTemplate = nullptr;
	}


	if (collectibleTemplate != nullptr) {
		for (int i = 0; i < numberOfCollectible; i++) {
			if (collectibleTemplate[i] != nullptr) {
				delete collectibleTemplate[i];
				collectibleTemplate[i] = nullptr;

			}
		}

		delete[] collectibleTemplate;
		collectibleTemplate = nullptr;
	}

	
}

void Map::renderMap(Console& console)
{
	// displays map on bottom half of console, 80 cells long and 16 cells high.
	const int yOffset = 9;

	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			console.writeToBuffer(j, 24-i, mapArray[i][j],BG_CYAN+FG_LIGHTMAGENTA);
		}
	}
}

void Map::renderMap(Console& console, int x, int y) {
	int playerX = x;
	
	int playerY = y;
	//16x80
	
	int mapOffsetX = playerX - 80 / 2;
	int mapOffsetY = playerY - 16 / 2;
	


	if (mapOffsetX + 80 > length) {
		mapOffsetX = length - 80;
	}
	if (mapOffsetY + 16 > height) {
		mapOffsetY = height - 16;
	}
	if (mapOffsetX < 0) {
		mapOffsetX = 0;
	}
	if (mapOffsetY < 0) {
		mapOffsetY = 0;
	}

	int colorScheme = 0;

	switch (currStage) {
	case 1:
		colorScheme = BG_RED + FG_BLACK;
		break;

	case 2:
		colorScheme = BG_YELLOW + FG_RED;
		break;

	case 3:
		colorScheme = BG_SILVER + FG_RED;
		break;

	case 4:
		colorScheme = BG_MAGENTA + BG_OLIVE;
		break;
		
	case 5:
		colorScheme = BG_CYAN;
		break;

	case 6:
		colorScheme = BG_BLUE + FG_BLACK;
		break;
		
	default:
		colorScheme = FG_WHITE;
		break;
	}


	for (int i = 0; i < getSmaller(16,height); i++){
		for (int j = 0; j < getSmaller(80,length); j++){
			if (tempMapArray[i + mapOffsetY][j + mapOffsetX]!=' ') {
				console.writeToBuffer(j, 24 - i, tempMapArray[i + mapOffsetY][j + mapOffsetX], colorScheme);
				tempMapArray[i + mapOffsetY][j + mapOffsetX] = ' ';
			}
			else {
				console.writeToBuffer(j, 24 - i, mapArray[i + mapOffsetY][j + mapOffsetX], colorScheme);

			}
		}
	}
}

char Map::getItem(int x, int y)
{
	if (x < 0 || y < 0 || x >= length || y >= height) {
		return INVALID;
	}
	else {
		// Gets the map character from a specifc position
		return mapArray[y][x];
	}
}

void Map::setItem(int x, int y, char symbol) {
	// sets value in maparray to be the character put in level text file
	if (x < 0 || y < 0 || x >= length || y >= height) {
		return;
	}
	else {
		mapArray[y][x] = symbol;
	}
}

char Map::getDefaultItem(int x, int y)
{
	if (x < 0 || y < 0 || x >= length || y >= height) {
		return INVALID;
	}
	else {
		// Gets the map character from a specifc position
		return mapTemplate[y][x];
	}
}


void Map::setDefaultItem(int x, int y) {
	// sets maparray specific value to default template containing blank space
	if (x < 0 || y < 0 || x >= length || y >= height) {
		return;
	}
	else {
		mapArray[y][x] = mapTemplate[y][x];
	}
}

void Map::setTempItem(int x, int y, char symbol) {
	if (x < 0 || y < 0 || x >= length || y >= height) {
		return;
	}
	else {
		tempMapArray[y][x] = symbol;
	}
}


int Map::getNumberOfEnemies() {
	return numberOfEnemies;
}


COORD Map::getPlayerPosition() {
	return playerStartingPos;
}

EntityTemplate** Map::getEnemyTemplate() {
	return enemyTemplate;
}

int Map::getNumberOfCollectibles() {
	return numberOfCollectible;
}

EntityTemplate** Map::getCollectibleTemplate() {
	return collectibleTemplate;
}