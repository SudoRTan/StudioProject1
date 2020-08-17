#include "Enemy.h"

#include <random>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

Enemy::Enemy()
{

}

Enemy::~Enemy()
{

}

void Enemy::Movement()
{
	for (int left = 0; left < 3; left++) // 3 is a temp number, change later or use different code for range of enemy movement
	{
		pos.moveLeft(); // call entity function to move left on map
	}
	for (int right = 0; right < 3; right++)
	{
		pos.moveRight(); // call entity function to move right on map
	}

	//print out map with updated x and y values of enemy (in main or somewhere else idk)
}
