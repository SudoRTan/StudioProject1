#include "Player.h"

Player::Player()
{
	position.setX(0);
	position.setY(1);
	canJump = 0;
	lastJumpTime = 0.0;
}

Player::~Player()
{

}

void Player::move(SKeyEvent KeyEvent[K_COUNT])
{
	if (KeyEvent[K_LEFT].keyDown)
	{
		position.setX(position.getX() - 1);
	}
	if (KeyEvent[K_RIGHT].keyDown)
	{
		position.setX(position.getX() + 1);
	}
	if (KeyEvent[K_UP].keyDown&&position.getY()==1)
	{
		if (canJump == 0)
		{
			canJump = 3;
		}
	}
}

void Player::updateHeight(Map& map, double g_dElapsedTime)
{
	
	if (g_dElapsedTime - lastJumpTime > 0.06 && canJump !=0)
	{
		position.setY(position.getY() + 1);

		lastJumpTime = g_dElapsedTime;
		canJump--;
	}
	else if (map.getMap(position.getX(),position.getY()-1)==EMPTY &&  g_dElapsedTime - lastJumpTime > 0.06)
	{
		position.setY(position.getY() - 1);
		lastJumpTime = g_dElapsedTime;
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

	console.writeToBuffer(playerX - mapOffsetX, 24- (playerY - mapOffsetY) , '9', FG_BLACK + BG_GRAY);
}

