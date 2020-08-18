#pragma once
#include "Entity.h"
#include "game.h"
#include "Framework/console.h"
#include "colors.h"


class Player :
	public Entity
{
public:
	Player();
	~Player();

	void move(Map& map,SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime);
	void updateHeight(Map& map, double g_dElapsedTime);
	void renderPlayer(Console& console);
};