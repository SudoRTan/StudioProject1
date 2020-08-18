#include "Map.h"
#include <fstream>

Map::Map()
{
	height = 16;
	length = 80;

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
	for (int i = 0; i < length; i++) {
		if (i % 2 == 0) {
			mapArray[0][i] = (char)FLOOR;
		}
		else {
			mapArray[0][i] = (char)FLOOR + 1;
		}
	}
}

Map::~Map()
{
	for (int i = 0; i < height; i++)
	{
		delete[] mapArray[i];
	}
	delete[] mapArray;
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

void Map::renderMap(Console& console, Player& player)
{
	int playerX = player.getPositionX();
	int playerY = player.getPositionY();

	//16x80
	
	int mapOffsetX = playerX - 80 / 2;
	int mapOffsetY = playerY - 16 / 2;
	
	if (mapOffsetX < 0)
	{
		mapOffsetX = 0;
	}
	if (mapOffsetY < 0)
	{
		mapOffsetY = 0;
	}
	if (mapOffsetX + 80 > length)
	{
		mapOffsetX = length-80;
	}

	console.writeToBuffer(0, 4, (char)48 + playerX, FG_BLACK + BG_WHITE);
	console.writeToBuffer(0, 5, (char)48 + playerY, FG_BLACK + BG_WHITE);
	console.writeToBuffer(0, 6, (char)48+mapOffsetX, FG_BLACK + BG_WHITE);
	console.writeToBuffer(0, 7, (char)48+mapOffsetY, FG_BLACK + BG_WHITE);

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < length; j++)
		{
			console.writeToBuffer(j, 24 - i, mapArray[i + mapOffsetY][j + mapOffsetX], BG_CYAN + FG_LIGHTMAGENTA);
		}
	}
}

char Map::getMap(int x, int y)
{
	// Gets the map character from a specifc position
	return mapArray[x][y];		
}

void Map::LoadMap(std::string filename, Console& console)
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