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
	changeInHeight = 0;
	dropping = false;
	lastTouched = 0.0;
}


Player::Player(int x, int y) {
	position.setX(x);
	position.setY(y);
	health = 20;
	canJump = 0;
	lastJumpTime = 0.0;
	lastMovementTime = 0.0;
	updateDelay = 0.04;
	changeInHeight = 0;
	dropping = false;
	lastTouched = 0.0;
}


Player::~Player()
{

}

void Player::move(Map& map, SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime)
{	
	int newX = position.getX();
	int newY = position.getY();



	if (KeyEvent[K_LEFT].keyDown && g_dElapsedTime - lastMovementTime > updateDelay)
	{
		newX--;
	}

	if (KeyEvent[K_RIGHT].keyDown && g_dElapsedTime - lastMovementTime > updateDelay)
	{
		newX++;

	}

	if (KeyEvent[K_UP].keyOnce && map.getItem(position.getX(), position.getY() - 1)!=EMPTY )
	{
		if (canJump == 0)
		{
			canJump = 3;
		}
	}

	if (KeyEvent[K_DOWN].keyTwice) {
		dropping = true;
	}



	if (map.getItem(newX, newY) == EMPTY) {
		lastMovementTime = g_dElapsedTime;

		map.setDefaultItem(position.getX(), position.getY());

		position.setX(newX);
		position.setY(newY);

		map.setItem(position.getX(), position.getY(), '9');

	}

}

void Player::updateHeight(Map& map, double g_dElapsedTime)
{	
	int newX = position.getX();
	int newY = position.getY();

	if (g_dElapsedTime - lastJumpTime > 0.06 && canJump !=0)
	{
		newY++;

		lastJumpTime = g_dElapsedTime;
		canJump--;
		changeInHeight++;
	
	}
	else if (dropping) {
		newY--;
		changeInHeight--;
		
	}

	else if (g_dElapsedTime - lastJumpTime > 0.06)
	{
		newY--;
		lastJumpTime = g_dElapsedTime;	
		changeInHeight--;
	}
	


	char itemAtNewLocation = map.getItem(newX, newY);


	if (itemAtNewLocation == EMPTY) {
		map.setDefaultItem(position.getX(), position.getY());
		position.setX(newX);
		position.setY(newY);
		map.setItem(position.getX(), position.getY(), '9');
	
	}
	else if (itemAtNewLocation == PLATFORM && (dropping || changeInHeight > 0)) {
		
		map.setDefaultItem(position.getX(), position.getY());
		position.setX(newX);
		position.setY(newY);
		map.setItem(position.getX(), position.getY(), '9');

	}

	else if  ( newY != position.getY()){
		canJump = 0;
	}
	
	changeInHeight = 0;
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
	if ((enemy.getPositionX() - position.getX() == 1 || enemy.getPositionX() - position.getX() == -1) && g_dElapsedTime - lastTouched > 0.5)
	{
		health = health - enemy.getDamage();
		lastTouched = g_dElapsedTime;
		//insert duck noises
	}
	else if ((enemy.getPositionY() - position.getY() == 1 || enemy.getPositionY() - position.getY() == -1) && lastTouched > 0.5)
	{
		health = health - enemy.getDamage();
		lastTouched = g_dElapsedTime;
		//insert goose noises
	}
}

char Player::getItemBelow(Map& map) {
	return map.getItem(position.getX(), position.getY());
}