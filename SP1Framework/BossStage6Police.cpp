#include "BossStage6Police.h"


BossStage6Police::BossStage6Police(int x, int y, int direction) {
	cleanUp();

	position.setX(x);
	position.setY(y);
	this->direction = direction;

	height = 3;
	width = 1;

	symbolArray = createArray(width, height);

	symbolArray[0][0] = 'A';
	symbolArray[1][0] = '|';

	switch (direction) {
	case LEFT:
		symbolArray[2][0] = '>';
		break;

	case RIGHT:
	default:
		symbolArray[2][0] = '<';
		break;
	}

	bullet = nullptr;

	lastFireTime = 0;
	fireDelay = 0.5;
}

BossStage6Police::~BossStage6Police() {
	cleanUp();

}

int BossStage6Police::update(Map& map, double elapsedTime, Player& player) {
	//patrol(map, elapsedTime, player);

		//updateNewPosition(map, position.getX(), position.getY());
	fire(elapsedTime);

	if (bullet != nullptr) {
		if (bullet->getHealth() == 0) {
			bullet->death(map);
			delete bullet;
			bullet = nullptr;
		}
		else {
			bullet->update(map, elapsedTime, &player);
		}
	}
	return 0;
}

void BossStage6Police::fire(double elapsedTime) {
	if (elapsedTime - lastFireTime > fireDelay) {
		lastFireTime = elapsedTime;

		int xOffSet = position.getX();
		switch (direction){
		case LEFT:
			xOffSet--;
			break;

		case RIGHT:
		default:
			xOffSet++;
			break;
		}


		if (bullet == nullptr) {
			bullet = new Projectile(xOffSet, position.getY(), direction, 1, (char)254, 0.5);
			lastFireTime = elapsedTime;
		}
		
	}
}

