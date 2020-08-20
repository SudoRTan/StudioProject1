#pragma once
#include "Entity.h"
#include "game.h"
#include "Framework/console.h"
#include "colors.h"
#include "Enemy.h"
#include "Weapon.h"
#include "MeleeWeapon.h"



class Player :
	public Entity
{
private:
	int changeInHeight;
	bool dropping;
	COORD enemyLocation;
	Weapon* weapon;

public:
	Player();
	Player(int x, int y);
	~Player();

	int move(Map& map,SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime);
	void updateHeight(Map& map, double g_dElapsedTime);
	void renderPlayer(Console& console);
	void touchEnemy(Enemy enemy, double g_dElapsedTime);

	char getItemBelow(Map& map);

	void setPosition(int x, int y);

	COORD getEnemyLocation();

	void attack(Map& map, SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, Enemy** enemyArray, int enemyArraySize);
};