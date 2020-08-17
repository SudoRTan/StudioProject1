#include "Player.h"

Player::Player()
{
	position.setX(0);
	position.setY(1);
}

Player::~Player()
{

}




void Player::move(SKeyEvent KeyEvent[K_COUNT]) {
	if (KeyEvent[K_LEFT].keyDown) {
		position.setX(position.getX() - 1);
	}
	if (KeyEvent[K_RIGHT].keyDown) {
		position.setX(position.getX() + 1);
	}
}