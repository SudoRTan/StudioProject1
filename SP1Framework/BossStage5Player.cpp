#include "BossStage5Player.h"

BossStage5Player::BossStage5Player()
{
	position.setX(1);
	position.setY(15);
	height = 1;
	width = 1;
	direction = RIGHT;
	cleanUp();
	symbolArray = createArray(width, height);
	symbolArray[0][0] = (char)80;
}

BossStage5Player::~BossStage5Player()
{
	cleanUp();
}

int BossStage5Player::update(Map& map, SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, Enemy** enemyArray, int enemyArraySize, Collectible** collectibleArray, int collectibleArraySize)
{
	int playerUpdateValue = 0;
	playerUpdateValue = move(map, KeyEvent, g_dElapsedTime, enemyArray, enemyArraySize);
	return playerUpdateValue;
}

int BossStage5Player::move(Map& map, SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, Enemy** enemyArray, int enemyArraySize)
{
	int newY = position.getY();

	if (KeyEvent[K_UP].keyDown && g_dElapsedTime - lastMovementTime > updateDelay)
	{
		newY++;
	}

	if (KeyEvent[K_DOWN].keyDown && g_dElapsedTime - lastMovementTime > updateDelay)
	{
		newY--;
	}

	if ((position.getY() != newY) && g_dElapsedTime - lastMovementTime > updateDelay)
	{
		bool validMove = canEntityMove(map, position.getX(), newY);
		if (validMove == true)
		{
			lastMovementTime = g_dElapsedTime;
			Enemy* enemyAtNewLocation = nullptr;
			for (int i = 0; i < width; i++)
			{
				for (int j = 0; j < height; j++)
				{
					if (enemyAtNewLocation == nullptr)
					{
						enemyAtNewLocation = getEnemy(position.getX() + i, newY + j, enemyArray, enemyArraySize);
					}
				}
			}
			if (enemyAtNewLocation != nullptr)
			{
				takeDamage(enemyAtNewLocation->getDamage(), g_dElapsedTime);
			}
			else {
				updateNewPosition(map, position.getX(), newY);
			}
		}
	}

	return NO_CHANGE;
}