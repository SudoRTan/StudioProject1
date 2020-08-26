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

Map::Map(int height, int length)
{
	this->height = height;
	this->length = length;

	playerStartingPos.X = 0;
	playerStartingPos.Y = 1;



	mapArray = new char* [height];
	for (int i = 0; i < height; i++)
	{
		mapArray[i] = new char[length];
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < length; j++) {
			mapArray[i][j] = EMPTY;
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
	setItem(3, 1, (char)FLOOR);
	setItem(4, 1, (char)FLOOR);
	setItem(5, 3, (char)FLOOR);
	setItem(6, 3, (char)FLOOR);
	setItem(7, 3, (char)FLOOR);
	setItem(8, 5, (char)FLOOR);
	setItem(9, 5, (char)FLOOR);
	setItem(10, 5, (char)FLOOR);

	setItem(15, 1, (char)FLOOR);
	setItem(15, 2, (char)FLOOR);
	setItem(15, 3, (char)FLOOR);
	setItem(15, 4, (char)FLOOR);
	setItem(15, 5, (char)FLOOR);

}

Map::Map(std::string fileName)
{
	height = 0;
	length = 0;

	playerStartingPos.X = 0;
	playerStartingPos.Y = 1;



	numberOfEnemies = 0;
	numberOfCollectible = 0;

	std::string line = "";
	int lines = 0;
	int columns = 0;

	std::ifstream file(fileName);

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
					numberOfEnemies++;
					break;
					
					//If the item is a collectible
				case HEALTH:
					numberOfCollectible++;
					break;

				default:
					break;
				}

			}

			if (lengthOfLine != length) {
				for (int i = lengthOfLine; i < length; i++) {
					mapArray[readingLine][i] = (char)EMPTY;
					mapTemplate[readingLine][i] = (char)EMPTY;

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
					enemyTemplate[enemyCounter]->postion.X = j;
					enemyTemplate[enemyCounter]->postion.Y = i;
					enemyTemplate[enemyCounter]->symbol = mapArray[i][j];
					enemyCounter++;
					mapArray[i][j] = EMPTY;
					mapTemplate[i][j] = EMPTY;
					break;

					//Collectible is at location
				case HEALTH:
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

	}

	file.close();
	
}

Map::~Map()
{
	for (int i = 0; i < height; i++)
	{
		delete[] mapArray[i];
		delete[] mapTemplate[i];
		delete[] tempMapArray[i];
	}
	delete[] mapArray;
	delete[] mapTemplate;
	delete[] tempMapArray;


	for (int i = 0; i < numberOfEnemies; i++) {
		delete enemyTemplate[i];
	}

	delete[] enemyTemplate;

	for (int i = 0; i < numberOfCollectible; i++) {
		delete collectibleTemplate[i];
	}

	delete[] collectibleTemplate;
}

void Map::renderMap(Console& console)
{
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

	/*
	console.writeToBuffer(0, 4, (char)48 + playerX, FG_BLACK + BG_WHITE);
	console.writeToBuffer(0, 5, (char)48 + playerY, FG_BLACK + BG_WHITE);
	console.writeToBuffer(0, 6, (char)48+mapOffsetX, FG_BLACK + BG_WHITE);
	console.writeToBuffer(0, 7, (char)48+mapOffsetY, FG_BLACK + BG_WHITE);
	*/

	for (int i = 0; i < getSmaller(16,height); i++){
		for (int j = 0; j < getSmaller(80,length); j++){
			if (mapArray[i + mapOffsetY][j + mapOffsetX] != tempMapArray[i + mapOffsetY][j + mapOffsetX]) {
				console.writeToBuffer(j, 24 - i, tempMapArray[i + mapOffsetY][j + mapOffsetX], BG_CYAN + FG_LIGHTMAGENTA);
				tempMapArray[i + mapOffsetY][j + mapOffsetX] = mapArray[i + mapOffsetY][j + mapOffsetX];
			}
			else {
				console.writeToBuffer(j, 24 - i, mapArray[i + mapOffsetY][j + mapOffsetX], BG_CYAN + FG_LIGHTMAGENTA);

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
	if (x < 0 || y < 0 || x >= length || y >= height) {
		return;
	}
	else {
		mapArray[y][x] = mapTemplate[y][x];
	}
}

void Map::setTempItem(int x, int y, char symbol) {
	tempMapArray[y][x] = symbol;
}

void Map::loadMap(std::string filename, Console& console)
{
	/*
This code consists of 2 sections in test2 which are seperately functional.
The 1st section pertains to reading the .txt file and getting the length & height of the level from there.
*/

	char map[20][20]; // map double array values TBD. Have not tested with larger maps yet. this was a 1am grind btw lolol
	int textlength = 10;
	int textheight = 10;

	std::ifstream textfile("./oopMapTest.txt");

	//if (!textfile)
	//{
	//	std::cout << "Could not open oopMapTest" << std::endl;
	//}
	//else
	//{
	//	std::cout << "Height of map before reading text file: " << textheight << std::endl;
	//	std::cout << "Length of map before reading text file: " << textlength << std::endl;

	//	for (int height = 0; height < 10; height++)
	//	{
	//		std::string line;
	//		if (std::getline(textfile, line).eof()) // calculate for height of map
	//		{
	//			textheight = height + 1;
	//		}
	//		std::string line2;
	//		if (std::getline(textfile, line2)) // calculate for length of map
	//		{
	//			textlength = line2.length();
	//		}
	//	}
	//	std::cout << "Height of map after reading text file: " << textheight << std::endl;
	//	std::cout << "Length of map after reading text file: " << textlength << std::endl;
	//}

	/*
	However, when coming to section 2 below, the code for updating each cell on the map from .txt to console, it breaks.
	Specifically, it prints out a map that seems to contain no empty space.
	It could potentially be something to do with the above code's std::getline(textfile, line) or something else messing with the ifstream textfile on line 47?
	I have tested the values of textlength and textheight, and they both function properly and carry over the dimensions of the map in .txt file.
	Hence, the problem does not come from textlength or textheight when used as variables in section 2.
	Currently for testing purposes, have '0' in .txt be updated to blank space, and everything else to be updated as '@'. Symbols can be changed as per requirement.
	*/

	for (int row = 0; row < textlength; row++)
	{
		for (int col = 0; col < textheight; col++)
		{
			textfile >> map[row][col];
			switch (map[row][col])
			{
			case '0':
			{
				map[row][col] = ' ';
				break;
			}
			case '1':
			{
				map[row][col] = '@';
				break;
			}
			// add more cases in future to 'render' other symbols on map like Enemy or Collectible to use values aside from 0 and 1
			}
		}
	}

	textfile.close(); // closes off access to textfile "oopMapTest.txt" at end of program.

	const int yOffset = 9;

	for (int h = 0; h < textheight; h++) 
	{
		for (int l = 0; l < textlength; l++) 
		{
			console.writeToBuffer(l, h + yOffset, mapArray[h][l], BG_CYAN + FG_LIGHTMAGENTA);
		}
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