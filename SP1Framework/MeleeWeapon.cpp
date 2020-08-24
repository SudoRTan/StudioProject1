#include "MeleeWeapon.h"

MeleeWeapon::MeleeWeapon() {
	setName("Melee");
	setDamage(10);

	useTime = 0.06;
	lastUseTime = 0.00;

	animationPhases = 3;
	currentAnimationPhase = 0;
	lastAnimateTime = 0;

}

MeleeWeapon::~MeleeWeapon() {

}

void MeleeWeapon::animate(Map& map, double g_dElapsedTime, int direction, int x, int y) {
	
	if (currentAnimationPhase != 0) {
		int offSet = 0;

		switch (direction) {
		case LEFT:
			offSet = -1;
			break;

		case RIGHT:
			offSet = 1;
			break;

		default:
			break;
		}


		/*
		OLD ANIMATIOM
		switch (currentAnimationPhase) {
		case 1:
			map.setTempItem(x + offSet, y, '0');
			map.setTempItem(x + offSet * 2, y - 1, '0');
			break;

		case 2:
			map.setTempItem(x + offSet, y, '0');
			map.setTempItem(x + offSet * 2, y, '0');
			break;

		case 3:
			map.setTempItem(x + offSet, y, '0');
			map.setTempItem(x + offSet * 2, y + 1, '0');
			break;

		default:
			break;

		}
		*/
		if (direction == RIGHT)
		{
			switch (currentAnimationPhase) {
			case 1:
				map.setTempItem(x + offSet, y, (char)POINTING_DOWNWARDS);
				map.setTempItem(x + offSet * 2, y - 1, (char)POINTING_DOWNWARDS);
				break;

			case 2:
				map.setTempItem(x + offSet, y, (char)POINTING_STRAIGHT);
				map.setTempItem(x + offSet * 2, y, (char)POINTING_STRAIGHT);
				break;

			case 3:
				map.setTempItem(x + offSet, y, (char)POINTING_UPWARDS);
				map.setTempItem(x + offSet * 2, y + 1, (char)POINTING_UPWARDS);
				break;

			default:
				break;

			}
		}
		if (direction == LEFT)
		{
			switch (currentAnimationPhase) {
			case 1:
				map.setTempItem(x + offSet, y, (char)POINTING_UPWARDS);
				map.setTempItem(x + offSet * 2, y - 1, (char)POINTING_UPWARDS);
				break;

			case 2:
				map.setTempItem(x + offSet, y, (char)POINTING_STRAIGHT);
				map.setTempItem(x + offSet * 2, y, (char)POINTING_STRAIGHT);
				break;

			case 3:
				map.setTempItem(x + offSet, y, (char)POINTING_DOWNWARDS);
				map.setTempItem(x + offSet * 2, y + 1, (char)POINTING_DOWNWARDS);
				break;

			default:
				break;

			}
		}

		if (g_dElapsedTime - lastAnimateTime > (useTime / animationPhases)) {
			lastAnimateTime = g_dElapsedTime;
			currentAnimationPhase--;
		}
	}
}

void MeleeWeapon::use(Map& map, Enemy** enemyArray, int enemyArraySize, double g_dElapsedTime, int direction, int x, int y) {
	
	if (g_dElapsedTime - lastUseTime > useTime) {
		lastUseTime = g_dElapsedTime;
		currentAnimationPhase = 3;

		if (direction == LEFT) {
			for (int i = 1; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					Enemy* enemyInRange = getEnemy(x - i, y + j, enemyArray, enemyArraySize);
					if (enemyInRange != nullptr) {
						enemyInRange->takeDamage(getDamage());
					}
				}
			}
		}

		else if (direction == RIGHT) {
			for (int i = 1; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					Enemy* enemyInRange = getEnemy(x + i, y + j, enemyArray, enemyArraySize);
					if (enemyInRange != nullptr) {
						enemyInRange->takeDamage(getDamage());
					}
				}
			}
		}
	}
}