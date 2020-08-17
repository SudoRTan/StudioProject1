#pragma once
#include "Entity.h"
#include "game.h"

class Player :
	public Entity
{
public:
	Player();
	~Player();

	void move(SKeyEvent KeyEvent[K_COUNT]);

};