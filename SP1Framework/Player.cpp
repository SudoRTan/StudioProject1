#include "Player.h"

Player::Player()
{
	position.setX(0);
	position.setY(1);
	canJump = 0;
	lastJumpTime = 0.0;
	lastMovementTime = 0.0;
	updateDelay = 0.03;
	changeInHeight = 0;
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

		//position.setX(position.getX() - 1);
	}
	if (KeyEvent[K_RIGHT].keyDown && g_dElapsedTime - lastMovementTime > updateDelay)
	{
		newX++;

		//position.setX(position.getX() + 1);
	}
	if (KeyEvent[K_UP].keyOnce && map.getItem(position.getX(), position.getY() - 1)!=EMPTY )
	{
		if (canJump == 0)
		{
			canJump = 3;
		}
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
		changeInHeight = 1;
	}
	else if (g_dElapsedTime - lastJumpTime > 0.06)
	{
		newY--;

		lastJumpTime = g_dElapsedTime;
		
		changeInHeight = -1;
	}

	char itemAtNewLocation = map.getItem(newX, newY);


	if (itemAtNewLocation == EMPTY) {

		map.setDefaultItem(position.getX(), position.getY());

		position.setX(newX);
		position.setY(newY);

		map.setItem(position.getX(), position.getY(), '9');
		changeInHeight = 0;

	}
	else if (itemAtNewLocation == '-' && changeInHeight == 1) {

		map.setDefaultItem(position.getX(), position.getY());

		position.setX(newX);
		position.setY(newY);

		map.setItem(position.getX(), position.getY(), '9');
		changeInHeight = 0;

	}

	else if  ( newY != position.getY()){
		canJump = 0;
	}

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

