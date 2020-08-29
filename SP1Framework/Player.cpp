#include "Player.h"

Player::Player()
{
	position.setX(0);
	position.setY(1);
	health = 20;
	maxHealth = 20;
	ammo = 0;
	maxAmmo = 20;
	canJump = 0;
	lastJumpTime = 0.0;
	lastMovementTime = 0.0;
	updateDelay = 0.04;
	updateHeightDelay = 0.06;

	dropping = false;
	jumping = false;

	lastDamageTime = 0.0;
	damageDelay = 0.3;


	direction = RIGHT;

	weapon = new RangedWeapon;


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
	maxHealth = 20;
	canJump = 0;
	lastJumpTime = 0.0;
	lastMovementTime = 0.0;
	updateDelay = 0.04;
	updateHeightDelay = 0.06;

	dropping = false;
	jumping = false;

	lastDamageTime = 0.0;
	damageDelay = 0.3;


	direction = RIGHT;

	weapon = new RangedWeapon;

	height = 3;
	width = 1;

	symbolArray = createArray(width, height);

	symbolArray[0][0] = PLAYER_LEGS;
	symbolArray[1][0] = PLAYER_BODY;
	symbolArray[2][0] = PLAYER_HEAD;

}


Player::~Player()
{
	cleanUp();
	delete weapon;
	weapon = nullptr;
}

int Player::getAmmo()
{
	if (weapon != nullptr)
	{
		return weapon->getAmmo();
	}
	else
	{
		return -1;
	}
}

std::string Player::getWeaponName() {
	if (weapon != nullptr)
	{
		return weapon->getName();
	}
	else
	{
		return "";
	}
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
	/*
	if (KeyEvent[K_UP].keyOnce && map.getItem(position.getX(), position.getY() - 1) != EMPTY)
	{
		if (canJump == 0)
		{
			canJump = 3;
		}
	}
	*/
	if (KeyEvent[K_UP].keyOnce && jumping == false)
	{
		jumping = true;
		canJump = 3;
		
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
		else if (map.getDefaultItem(newX, newY) == 'D') {
			return PLAYER_REACHED_DOOR;
		}
		//else if (map.getItem(newX, newY) == 'H') {
		//	map.setItem(newX, newY, EMPTY);
		//	return PLAYER_GOT_HEALTH;
		//}
	}

	

	return NO_CHANGE;

}

int Player::updateHeight(Map& map, double g_dElapsedTime, Enemy** enemyArray, int enemyArraySize)
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

				if (canJump == 0) {
					jumping = false;
				}

 				takeDamage(enemyAtNewLocation->getDamage(), g_dElapsedTime);
			}

			else {
				updateNewPosition(map, newX, newY);

			}
		}
	}
	/*else if (map.getItem(newX, newY - 1) == HEALTH_COLLECTIBLE) {
		return PLAYER_GOT_HEALTH;
	}*/

	switch (getItemBelow(map)) {
	case DOOR:
		return PLAYER_REACHED_DOOR;
		break;

	case LAVA:
		setHealth(0);
		break;

	case '=':
	case '-':
		jumping = false;
		break;

	default:
		break;

	}
	
	dropping = false;
	return NO_CHANGE;

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
		PlaySound(TEXT("./Sounds/damageTaken.wav"), NULL, SND_FILENAME | SND_ASYNC);
		//insert duck noises
	}
	else if ((enemy.getPositionY() - position.getY() == 1 || enemy.getPositionY() - position.getY() == -1) && lastDamageTime > 0.5)
	{
		health = health - enemy.getDamage();
		lastDamageTime = g_dElapsedTime;
		PlaySound(TEXT("./Sounds/damageTaken.wav"), NULL, SND_FILENAME | SND_ASYNC);
		//insert goose noises
	}
}


char Player::getItemBelow(Map& map) {
	return map.getDefaultItem(position.getX(), position.getY() - 1);
}

void Player::setPosition(int x, int y) {
	position.setX(x);
	position.setY(y);
}

void Player::resetWeapon()
{
	if (weapon != nullptr)
	{
		delete weapon;
		weapon = nullptr;
	}
}



int Player::update(Map& map, SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, Enemy** enemyArray, int enemyArraySize, Collectible** collectibleArray, int collectibleArraySize) {
	int playerUpdateValue = 0;
	playerUpdateValue = move(map, KeyEvent, g_dElapsedTime, enemyArray, enemyArraySize);
	if (playerUpdateValue == NO_CHANGE) {
		playerUpdateValue = updateHeight(map, g_dElapsedTime, enemyArray, enemyArraySize);
		
		// Update Weapon if weapon != nullptr
		if (weapon != nullptr) {
			weapon->update(map, enemyArray, enemyArraySize, g_dElapsedTime, direction, position.getX(), position.getY(), KeyEvent[K_SPACE].keyOnce);
		}
	}

	Collectible* collectibleInLocation = nullptr;
	
	getCollectible(position.getX(), position.getY(), collectibleArray, collectibleArraySize);

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			if (collectibleInLocation == nullptr) {
				collectibleInLocation = getCollectible(position.getX() + i, position.getY() + j, collectibleArray, collectibleArraySize);
			}
		}
	}


	if (collectibleInLocation != nullptr) {
		int collectibleType = collectibleInLocation->getType();
		switch (collectibleType) {
		case HEALTH:
			resetHealth();
			collectibleInLocation->collect();
			PlaySound(TEXT("./Sounds/collectHealth.wav"), NULL, SND_FILENAME | SND_ASYNC);
			break;
		case AMMO:
			if (weapon != nullptr) {
				weapon->replenishAmmo();
			}
			collectibleInLocation->collect();
			PlaySound(TEXT("./Sounds/collectAmmo.wav"), NULL, SND_FILENAME | SND_ASYNC);
			break;

		case SWORD:
			if (weapon != nullptr) {
				delete weapon;
			}
			weapon = new MeleeWeapon();
			collectibleInLocation->collect();
			break;

		case GUN:
			if (weapon != nullptr) {
				delete weapon;
			}
			weapon = new RangedWeapon();
			ammo = 20;
			collectibleInLocation->collect();

		default:
			break;
		}
	}

	return playerUpdateValue;
	
}

void Player::replenishAmmo() {
	if (weapon != nullptr) {
		weapon->replenishAmmo();
	}
}