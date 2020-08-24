#include "Player.h"

Player::Player()
{
	position.setX(0);
	position.setY(1);
	health = 20;
	canJump = 0;
	lastJumpTime = 0.0;
	lastMovementTime = 0.0;
	updateDelay = 0.04;
	updateHeightDelay = 0.06;

	dropping = false;

	lastDamageTime = 0.0;
	damageDelay = 0.3;

	enemyLocation.X = 0;
	enemyLocation.Y = 0;

	direction = RIGHT;

	weapon = new MeleeWeapon;


	height = 3;
	width = 1;

	symbolArray = createArray(width, height);

	symbolArray[0][0] = PLAYER_LEGS;
	symbolArray[1][0] = PLAYER_BODY;
	symbolArray[2][0] = PLAYER_HEAD;
}


Player::Player(int x, int y) {
	position.setX(x);
	position.setY(y);
	health = 20;
	canJump = 0;
	lastJumpTime = 0.0;
	lastMovementTime = 0.0;
	updateDelay = 0.04;
	updateHeightDelay = 0.06;

	dropping = false;

	lastDamageTime = 0.0;
	damageDelay = 0.3;
	
	enemyLocation.X = 0;
	enemyLocation.Y = 0;

	direction = RIGHT;

	weapon = new MeleeWeapon;

	height = 3;
	width = 1;

	symbolArray = createArray(width, height);

	symbolArray[0][0] = PLAYER_LEGS;
	symbolArray[1][0] = PLAYER_BODY;
	symbolArray[2][0] = PLAYER_HEAD;

}


Player::~Player()
{

}

int Player::move(Map& map, SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, Enemy** enemyArray, int enemyArraySize)
{	
	int newX = position.getX();
	int newY = position.getY();

	

	if (KeyEvent[K_LEFT].keyDown && g_dElapsedTime - lastMovementTime > updateDelay)
	{
		direction = LEFT;
		newX--;
	}

	if (KeyEvent[K_RIGHT].keyDown && g_dElapsedTime - lastMovementTime > updateDelay)
	{
		direction = RIGHT;
		newX++;

	}

	if (KeyEvent[K_UP].keyOnce && map.getItem(position.getX(), position.getY() - 1) != EMPTY)
	{
		if (canJump == 0)
		{
			canJump = 3;
		}
	}

	if (KeyEvent[K_DOWN].keyTwice) {
		dropping = true;
	}

	if ((position.getX() != newX || position.getY() != newY) && g_dElapsedTime - lastMovementTime > updateDelay) {
		bool validMove = canEntityMove(map, newX, newY);
		if (validMove) {
			lastMovementTime = g_dElapsedTime;

			Enemy* enemyAtNewLocation = nullptr;
			
			for (int i = 0; i < width; i++) {
				for (int j = 0; j < height; j++) {
					if (enemyAtNewLocation == nullptr) {
						enemyAtNewLocation = getEnemy(newX + i, newY + j, enemyArray, enemyArraySize);
					}
				}
			}
			if (enemyAtNewLocation != nullptr) {
				takeDamage(enemyAtNewLocation->getDamage(), g_dElapsedTime);
			}

			else {
				updateNewPosition(map, newX, newY);
			}
		}
		else if (map.getItem(newX, newY) == 'D') {
			return PLAYER_REACHED_DOOR;
		}
	}

	

	return NO_CHANGE;

}

void Player::updateHeight(Map& map, double g_dElapsedTime, Enemy** enemyArray, int enemyArraySize)
{	
	int newX = position.getX();
	int newY = position.getY();
	if (g_dElapsedTime - lastJumpTime > updateHeightDelay) {
		if (canJump != 0)
		{
			newY++;
			canJump--;

		}
		else if (dropping) {
			newY--;

		}

		else if (getItemBelow(map) == EMPTY)
		{
			newY--;

		}
	}

	if (position.getX() != newX || position.getY() != newY) {
		bool validMove = canEntityMove(map, newX, newY);
		if (validMove) {
			lastJumpTime = g_dElapsedTime;
			
			Enemy* enemyAtNewLocation = nullptr;

			for (int i = 0; i < width; i++) {
				for (int j = 0; j < height; j++) {
					if (enemyAtNewLocation == nullptr) {
						enemyAtNewLocation = getEnemy(newX + i, newY + j, enemyArray, enemyArraySize);
					}
				}
			}
			if (enemyAtNewLocation != nullptr) {
				takeDamage(enemyAtNewLocation->getDamage(), g_dElapsedTime);
			}

			else {
				updateNewPosition(map, newX, newY);

			}
		}
	}

	dropping = false;

}

void Player::renderPlayer(Console& console) {
	int playerX = getPositionX();
	int playerY = getPositionY();

	//16x80

	int mapOffsetX = playerX - 80 / 2;
	int mapOffsetY = playerY - 16 / 2;

	if (mapOffsetX < 0) {
		mapOffsetX = 0;
	}
	if (mapOffsetY < 0) {
		mapOffsetY = 0;
	}

	if (mapOffsetX + 80 > 128) {
		mapOffsetX = 128 - 80;
	}
	if (mapOffsetY + 16 > 16) {
		mapOffsetY = 16 - 16;
	}

	console.writeToBuffer(playerX - mapOffsetX, 24- (playerY - mapOffsetY) , '9', FG_BLACK + BG_GRAY);
}

void Player::touchEnemy(Enemy enemy, double g_dElapsedTime)
{
	if ((enemy.getPositionX() - position.getX() == 1 || enemy.getPositionX() - position.getX() == -1) && g_dElapsedTime - lastDamageTime > 0.5)
	{
		health = health - enemy.getDamage();
		lastDamageTime = g_dElapsedTime;
		//insert duck noises
	}
	else if ((enemy.getPositionY() - position.getY() == 1 || enemy.getPositionY() - position.getY() == -1) && lastDamageTime > 0.5)
	{
		health = health - enemy.getDamage();
		lastDamageTime = g_dElapsedTime;
		//insert goose noises
	}
}

bool Player::reachDoor()
{
	if ((position.getX() + 1 == 'D'))
	{
		return true;
	}
	else
	{
		return false;
	}
}

char Player::getItemBelow(Map& map) {
	return map.getDefaultItem(position.getX(), position.getY() - 1);
}

void Player::setPosition(int x, int y) {
	position.setX(x);
	position.setY(y);
}

COORD Player::getEnemyLocation() {
	return enemyLocation;
}

void Player::attack(Map& map, SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, Enemy** enemyArray, int enemyArraySize) {
	if (weapon != nullptr) {
		weapon->animate(map, g_dElapsedTime, direction, position.getX(), position.getY());

		if (KeyEvent[K_SPACE].keyOnce) {
			weapon->use(map, enemyArray, enemyArraySize, g_dElapsedTime, direction, position.getX(), position.getY());
		}
	}
			
}

int Player::update(Map& map, SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, Enemy** enemyArray, int enemyArraySize) {
	int playerUpdateValue = 0;
	playerUpdateValue = move(map, KeyEvent, g_dElapsedTime, enemyArray, enemyArraySize);
	updateHeight(map, g_dElapsedTime, enemyArray, enemyArraySize);
	attack(map, KeyEvent, g_dElapsedTime, enemyArray, enemyArraySize);
	
	return playerUpdateValue;
}