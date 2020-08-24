#pragma once
#include "Entity.h"
#include "game.h"
#include "Framework/console.h"
#include "colors.h"
#include "Enemy.h"
#include "Weapon.h"
#include "MeleeWeapon.h"

enum PLAYER_ELEMENTS {
	PLAYER_HEAD = '0',
	PLAYER_BODY = '|',
	PLAYER_LEGS = 'A'
};

class Player :
	public Entity
{
private:
	bool dropping;
	double updateHeightDelay;

	COORD enemyLocation;
	Weapon* weapon;

	int move(Map& map, SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, Enemy** enemyArray, int enemyArraySize);
	void updateHeight(Map& map, double g_dElapsedTime, Enemy** enemyArray, int enemyArraySize);
	void attack(Map& map, SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, Enemy** enemyArray, int enemyArraySize);

public:
	Player();
	Player(int x, int y);
	~Player();

	
	void renderPlayer(Console& console);
	void touchEnemy(Enemy enemy, double g_dElapsedTime);

	int update(Map& map, SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, Enemy** enemyArray, int enemyArraySize);

	char getItemBelow(Map& map);

	void setPosition(int x, int y);

	COORD getEnemyLocation();

};