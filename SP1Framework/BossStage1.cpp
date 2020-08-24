#include "BossStage1.h"
static int fireCount = 0;

BossStage1::BossStage1()
{
	for (int i = 0; i < 5; i++)
	{
		fireVector.push_back(new BossStage1Fire);
	}
}

BossStage1::~BossStage1()
{
	
}

void BossStage1::update()
{
	for (int i = 0; i < fireVector.size(); i++)
	{
		//update map
		// )
		//(_) this be the fire symbol
	}
}

