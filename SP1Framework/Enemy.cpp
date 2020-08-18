#include "Enemy.h"

#include <random>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

Enemy::Enemy()
{
	damagetaken = 0;
	// test spawning of enemies on map using (5,4) as test case
	enemypos.setX(5);
	enemypos.setY(4);
}

Enemy::~Enemy()
{

}

void Enemy::LRMovement()
{
	for (int left = 0; left < 3; left++) // 3 is a temp number, change later or use different code for range of enemy movement
	{
		enemypos.setX(enemypos.getX() - 1); // call entity function to move left on map
	}
	for (int right = 0; right < 3; right++)
	{
		enemypos.setX(enemypos.getX() + 1); // call entity function to move right on map
	}

	//print out map with updated x and y values of enemy (in main or somewhere else idk)
}

void Enemy::UDMovement()
{
	for (int up = 0; up < 3; up++) // 3 is a temp number, change later or use different code for range of enemy movement
	{
		enemypos.setY(enemypos.getY() + 1); // call entity function to move up on map
	}
	for (int down = 0; down < 3; down++)
	{
		enemypos.setY(enemypos.getY() - 1); // call entity function to move down on map
	}

	//print out map with updated x and y values of enemy (in main or somewhere else idk)
}

int Enemy::PlayerContact(Position playerpos) // pass in player's position object into playerpos
{
	if ((playerpos.getX() == enemypos.getX()) && (playerpos.getY() == enemypos.getY())) // check if player into enemy
	{
		damagetaken = 2;
		// reduce health by some amount
	}
	return damagetaken;
}

// using setDamage function in Entity.h, setHealth(getHealth() - setDamage(PlayerContact()))
// set current health = initial health - set damage(return statement in Enemy::PlayerContact())
