#include "BossStage1Fire.h"

BossStage1Fire::BossStage1Fire()
{
	setHealth(3);
	damageDelay = 0.1;
	cleanUp();
	height = 2;
	width = 3;
	symbolArray = createArray(width, height);
	symbolArray[0][0] = ' ';
	symbolArray[0][1] = ')';
	symbolArray[0][2] = ' ';
	symbolArray[1][0] = '(';
	symbolArray[1][1] = '_';
	symbolArray[1][2] = ')';
}

BossStage1Fire::BossStage1Fire(std::vector<BossStage1Fire*>& fireVector)
{
	bool setPositionCheck = false;
	while (setPositionCheck = false)
	{
		int positionCheckPass = 0;
		int tempX = 4 * (rand() % 5);
		int tempY = 1 + 3 * (rand() % 24);
		for (int i = 0; i < fireVector.size(); i++)
			if (tempX != fireVector.at(i)->getPositionX() && tempY != fireVector.at(i)->getPositionY())
				positionCheckPass++;
		if (positionCheckPass == fireVector.size())
			setPositionCheck = true;
	}
	setHealth(3);
	damageDelay = 0.1;
	cleanUp();
	height = 2;
	width = 3;
	symbolArray = createArray(width, height);
	symbolArray[0][0] = ' ';
	symbolArray[0][1] = ')';
	symbolArray[0][2] = ' ';
	symbolArray[1][0] = '(';
	symbolArray[1][1] = '_';
	symbolArray[1][2] = ')';
}

BossStage1Fire::~BossStage1Fire()
{

}

int BossStage1Fire::update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, int& gameState)
{
	return 0;
}