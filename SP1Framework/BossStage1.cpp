#include "BossStage1.h"
static int fireCount = 0;

BossStage1::BossStage1(Player* player, double g_dElapsedTime):Stage(player) //add spawning of water gun here
{
	playerOnFire = false;
	lastSpawnTime = g_dElapsedTime;
	timer = g_dElapsedTime;
	for (int i = 0; i < 5; i++)
	{
		fireVector.push_back(new BossStage1Fire(3 * (rand() % 24), 1 + 3 * i));
	}
}

BossStage1::~BossStage1()
{
		
}

void BossStage1::update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, int& gameState)
{
	entityManager.update(*map, KeyEvent, g_dElapsedTime, gameState);

	if (fireVector.empty() == true)
	{
		gameState = FINISHED_LEVEL;
	}
	if (player->getHealth() <= 0 || g_dElapsedTime - timer > 180)
	{
		gameState = PLAYER_DEATH;
	}

	for (int i = 0; i < fireVector.size(); i++) //require testing if vector resizes after delete
	{
		if (fireVector.at(i)->getHealth() <= 0)
		{
			fireVector.at(i)->death(*map);
			delete fireVector.at(i);
			fireVector.at(i) = nullptr;
			//fireVector.pop_back(); uncomment if doesnt resize, also require testing
		}
		else {
			fireVector.at(i)->update(*map, g_dElapsedTime, *player);
		}
	}
	if (g_dElapsedTime - lastSpawnTime > 5)
	{
		int numberOfFire = fireVector.size();
		for (int i = 0; i < numberOfFire; i++)
		{
			if (fireVector.at(i)->getCanSpawnLeft() == true && fireVector.at(i)->getCanSpawnRight() == true)
				switch (rand() % 2)
				{
				case 0:
					fireVector.push_back(new BossStage1Fire(fireVector.at(i)->getPositionX() - 3, fireVector.at(i)->getPositionY()));
					lastSpawnTime = g_dElapsedTime;
					break;
				case 1:
					fireVector.push_back(new BossStage1Fire(fireVector.at(i)->getPositionX() + 3, fireVector.at(i)->getPositionY()));
					lastSpawnTime = g_dElapsedTime;
					break;
				}
			else if (fireVector.at(i)->getCanSpawnLeft() == true && fireVector.at(i)->getCanSpawnRight() == false)
			{
				fireVector.push_back(new BossStage1Fire(fireVector.at(i)->getPositionX() - 3, fireVector.at(i)->getPositionY()));
				lastSpawnTime = g_dElapsedTime;
			}
			else if (fireVector.at(i)->getCanSpawnLeft() == false && fireVector.at(i)->getCanSpawnRight() == true)
			{
				fireVector.push_back(new BossStage1Fire(fireVector.at(i)->getPositionX() + 3, fireVector.at(i)->getPositionY()));
				lastSpawnTime = g_dElapsedTime;
			}
		}
	}
	for (int i = 0; i < fireVector.size(); i++)
		fireVector.at(i)->updateSpawnBool(map);
}
/*
void BossStage1::checkPlayerPosition(Player player, double g_dElapsedTime)
{
	for (int i = 0; i < fireVector.size(); i++)
	{
		if (fireVector.at(i)->getPositionX() == player.getPositionX() && fireVector.at(i)->getPositionY() == player.getPositionY())
		{
			playerOnFire = true;
		}
		else if (fireVector.at(i)->getPositionX() - player.getPositionX() > -5 && fireVector.at(i)->getPositionX() - player.getPositionX() < 5 && fireVector.at(i)->getPositionY() == player.getPositionY())
		{ //change to normal weapon fire detection
			fireVector.at(i)->takeDamage(1, g_dElapsedTime);
		}
	}
}
*/