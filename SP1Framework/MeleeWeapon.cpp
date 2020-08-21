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
					Enemy* enemyInRange = getEnemy(x - i, j - 1 + i, enemyArray, enemyArraySize);
					if (enemyInRange != nullptr) {
						enemyInRange->takeDamage(getDamage());
					}
				}
			}
		}

		else if (direction == RIGHT) {
			for (int i = 1; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					Enemy* enemyInRange = getEnemy(x + i, j - 1 + i, enemyArray, enemyArraySize);
					if (enemyInRange != nullptr) {
						enemyInRange->takeDamage(getDamage());
					}
				}
			}
		}
	}
}