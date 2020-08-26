#include "BossStage1.h"
static int fireCount = 0;

BossStage1::BossStage1(Player* player):Stage(player) //add spawning of water gun here
{
	playerOnFire = false;
	lastSpawnTime = 0;
	for (int i = 0; i < 5; i++)
	{
		fireVector.push_back(new BossStage1Fire);
	}
}

BossStage1::~BossStage1()
{
		
}

void BossStage1::update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, int& gameState)
{
	//int playerReturnValue = player->update(*map, KeyEvent, g_dElapsedTime, entityManager.enemy, numOfEnemies);

	if (fireVector.empty() == true)
	{
		gameState = FINISHED_LEVEL;
	}
	if (player->getHealth() <= 0)
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
	}
	spawnFire(g_dElapsedTime);
}

void BossStage1::spawnFire(double g_dElapsedTime)
{
	if (g_dElapsedTime - lastSpawnTime > 5)
	{
		lastSpawnTime = g_dElapsedTime;
		if (fireVector.size() < 120)
		{
			int firePresent = fireVector.size();
			for (int i = 0; i < firePresent; i++)
			{
				fireVector.push_back(new BossStage1Fire(fireVector));
			}
		}
	}
}

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