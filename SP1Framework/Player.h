#pragma once
#include "Entity.h"
#include "game.h"
#include "Framework/console.h"
#include "colors.h"
#include "Enemy.h"
#include "Weapon.h"
#include "MeleeWeapon.h"
#include "RangedWeapon.h"
#include "Collectible.h"

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
	bool jumping;

	double updateHeightDelay;

	Weapon* weapon;

	virtual int move(Map& map, SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, Enemy** enemyArray, int enemyArraySize);
	int updateHeight(Map& map, double g_dElapsedTime, Enemy** enemyArray, int enemyArraySize);


public:
	Player();
	Player(int x, int y);
	~Player();

	std::string getWeaponName();
	int getAmmo();
	
	void renderPlayer(Console& console);
	void touchEnemy(Enemy enemy, double g_dElapsedTime);

	virtual int update(Map& map, SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, Enemy** enemyArray, int enemyArraySize, Collectible** collectibleArray, int collectibleArraySize);

	char getItemBelow(Map& map);

	void setPosition(int x, int y);

	void resetWeapon();
	void replenishAmmo();


};