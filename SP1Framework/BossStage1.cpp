 #include "BossStage1.h"
static int fireCount = 0;

BossStage1::BossStage1(Player* player, double g_dElapsedTime):Stage(player) //add spawning of water gun here
{
	playerOnFire = false;
	lastSpawnTime = g_dElapsedTime;
	timer = g_dElapsedTime;
	/**
	for (int i = 0; i < 5; i++)
	{
		fireVector.push_back(new BossStage1Fire(3 * (rand() % 24), 1 + 3 * i));
	}
	*/



	//currNumberOfFires = 5;

	maxNumberOfFires = 200;
	
	fire = new Enemy * [maxNumberOfFires];
	
	for (int i = 0; i < maxNumberOfFires; i++) {
		fire[i] = nullptr;
	}

	for (int i = 0; i < 5; i++) {
		fire[i] = new BossStage1Fire(rand() % 118, 1 + 3 * i);
	}

}

BossStage1::~BossStage1()
{
	if (fire != nullptr) {
		for (int i = 0; i < maxNumberOfFires; i++) {
			if (fire[i] != nullptr) {
				delete fire[i];
				fire[i] = nullptr;
			}
		}
		delete[] fire;
		fire = nullptr;
	}
	
}

void BossStage1::update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, int& gameState)
{
	entityManager.update(*map, KeyEvent, g_dElapsedTime, gameState, fire, maxNumberOfFires);
	/*
	for (int i = 0; i < 5; i++) {
		fire[i]->update(*map, g_dElapsedTime, *player);
	}
	*/
	int numberOfFires = BossStage1Fire::getNumberOfFires();
	if (g_dElapsedTime - lastSpawnTime > 5) {

		for (int i = 0; i < numberOfFires; i++) {
			if (fire[i] != nullptr) {

				Enemy* enemyOnTheLeft = getEnemy(fire[i]->getPositionX() - 3, fire[i]->getPositionY(), fire, 200);
				Enemy* enemyOnTheRight = getEnemy(fire[i]->getPositionX() + 3, fire[i]->getPositionY(), fire, 200);

				if (enemyOnTheLeft == nullptr && fire[i]->getPositionX() - 3 > 0) {
					int j = 0;
					while (true) {
						if (fire[j] == nullptr) {
							fire[j] = new BossStage1Fire(fire[i]->getPositionX() - 3, fire[i]->getPositionY());
							break;
						}
						else if (j == 200){
							break;
						}
						else {
							j++;
						}
					}

					//fire[BossStage1Fire::getNumberOfFires()] = new BossStage1Fire(fire[i]->getPositionX() - 3, fire[i]->getPositionY());
				}
				if (enemyOnTheRight == nullptr && fire[i]->getPositionX() + 3 < 118) {
					int j = 0;
					while (true) {
						if (fire[j] == nullptr) {
							fire[j] = new BossStage1Fire(fire[i]->getPositionX() + 3, fire[i]->getPositionY());
							break;
						}
						else if (j == 200) {
							break;
						}
						else {
							j++;
						}
					}

					//fire[BossStage1Fire::getNumberOfFires()] = new BossStage1Fire(fire[i]->getPositionX() + 3, fire[i]->getPositionY());
				}
			}
		}
	}
	if (BossStage1Fire::getNumberOfFires() != numberOfFires) {
		lastSpawnTime = g_dElapsedTime;

	}

	for (int i = 0; i < maxNumberOfFires; i++) {
		if (fire[i] == nullptr) {
			for (int j = i; j < maxNumberOfFires - 1; j++) {
				fire[j] = fire[j + 1];
			}
			fire[maxNumberOfFires - 1] = nullptr;
		}
	}

	
	/*
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
		*/
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