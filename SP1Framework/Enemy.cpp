#include "Enemy.h"

#include <random>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

Enemy::Enemy()
{
	IsPlayerHit = false;
	// test spawning of enemies on map using (5,0) as test case
	enemypos.setX(5);
	enemypos.setY(4);
}

Enemy::~Enemy()
{

}

void Enemy::Movement()
{
	for (int left = 0; left < 3; left++) // 3 is a temp number, change later or use different code for range of enemy movement
	{
		moveLeft(); // call entity function to move left on map
	}
	for (int right = 0; right < 3; right++)
	{
		moveRight(); // call entity function to move right on map
	}

	//print out map with updated x and y values of enemy (in main or somewhere else idk)
}

void Enemy::PlayerContact(Position playerpos)
{
	if ((playerpos.getX() == enemypos.getX()) && (playerpos.getY() == enemypos.getY())) // check if player moves over collectible
	{
		IsPlayerHit = true;
		// reduce health by some amount
	}
}
