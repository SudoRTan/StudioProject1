#pragma once
#include "Player.h"
#include "Enemy.h"
class BossStage1Fire :
	public Enemy
{
public:
	BossStage1Fire();
	~BossStage1Fire();
	void takeDamage(Player player);
};