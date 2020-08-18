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

	void move(SKeyEvent KeyEvent[K_COUNT]);
	void updateHeight(double g_dElapsedTime);
	void renderPlayer(Console& console);

};