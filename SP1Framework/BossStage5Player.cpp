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
	symbolArray[0][0] == (char)80;
}

BossStage5Player::~BossStage5Player()
{
	cleanUp();
}

void update(Map& map, SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, Enemy** enemyArray, int enemyArraySize, Collectible** collectibleArray, int collectibleArraySize)
{

}