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
	//Update Entitys on the map
	entityManager.update(*map, KeyEvent, g_dElapsedTime, gameState, fire, maxNumberOfFires);


	// Move all the elements in the array to the start
	for (int i = 0; i < maxNumberOfFires; i++) {
		if (fire[i] == nullptr) {
			for (int j = i; j < maxNumberOfFires - 1; j++) {
				fire[j] = fire[j + 1];
			}
			fire[maxNumberOfFires - 1] = nullptr;
		}
	}

	//Gets current amount of fires
	int numberOfFires = BossStage1Fire::getNumberOfFires();



	// If it was 5 sec since last spawn 
	if (g_dElapsedTime - lastSpawnTime > 5) {

		// Loops through all current fires
		for (int i = 0; i < numberOfFires; i++) {
			// double check that current fire[i] is not a nullptr
			if (fire[i] != nullptr) {
				//Get location of fire
				int currX = fire[i]->getPositionX();
				int currY = fire[i]->getPositionY();

				//Check if any enemies on the left or right of the current fire
				Enemy* enemyOnTheLeft = getEnemy(currX - 3, currY, fire, 200);
				Enemy* enemyOnTheRight = getEnemy(currX + 3, currY, fire, 200);

				// If no enemies on the left + theres space on the left
				if (enemyOnTheLeft == nullptr && currX - 3 > 0) {

					//Loop through the fire array to spawn a new fire
					int j = 0;
					while (true) {
						//Check to make sure that array does not go out of index
						if (j == maxNumberOfFires) {
							break;
						}
						else if (fire[j] == nullptr) {
							fire[j] = new BossStage1Fire(currX - 3, currY);
							break;
						}
						else {
							j++;
						}
					}
				}

				// If no enemies on the right + theres space on the left
				if (enemyOnTheRight == nullptr && currX + 3 < 118) {

					//Loop through the fire array to spawn a new fire
					int j = 0;
					while (true) {
						//Check to make sure that array does not go out of index
						if (j == maxNumberOfFires) {
							break;
						}
						else if (fire[j] == nullptr) {
							fire[j] = new BossStage1Fire(currX + 3, currY);
							break;
						}
						else {
							j++;
						}
					}
				}
			}
		}
	}
	// If more fires are spawned
	if (BossStage1Fire::getNumberOfFires() != numberOfFires) {
		//Reset last spawn time;
		lastSpawnTime = g_dElapsedTime;

	}

	// If no more fires are left on the screen
	if (numberOfFires == 0) {
		gameState = LEVEL_COMPLETE_MENU;
	}

}