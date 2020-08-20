#include "MeleeWeapon.h"

MeleeWeapon::MeleeWeapon() {
	setName("Melee");
	setDamage(10);
	phase = 0;
	lastAnimateTime = 0;

}

MeleeWeapon::~MeleeWeapon() {

}

void MeleeWeapon::animate(Map& map, double g_dElapsedTime, int direction, int x, int y) {
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

	if (phase != 0) {
		map.setDefaultItem(x + offSet, y + 1);
		map.setDefaultItem(x + offSet * 2, y + 1);
		map.setDefaultItem(x + offSet, y);
		map.setDefaultItem(x + offSet * 2, y);
		map.setDefaultItem(x + offSet, y - 1);
		map.setDefaultItem(x + offSet * 2, y - 1);

	}
	if (g_dElapsedTime - lastAnimateTime > 0.02 && phase != 0) {
	

		map.setDefaultItem(x + offSet, y + 1);
		map.setDefaultItem(x + offSet * 2, y + 1);
		map.setDefaultItem(x + offSet, y);
		map.setDefaultItem(x + offSet * 2, y);
		map.setDefaultItem(x + offSet, y - 1);
		map.setDefaultItem(x + offSet * 2, y - 1);


		switch (phase) {
		case 2:
			map.setItem(x + offSet, y, '0');
			map.setItem(x + offSet * 2, y - 1, '0');
			break;

		case 3:
			map.setItem(x + offSet, y, '0');
			map.setItem(x + offSet * 2, y, '0');
			break;

		case 4:
			map.setItem(x + offSet, y, '0');
			map.setItem(x + offSet * 2, y + 1, '0');
			break;

		default:
			break;
		}
		phase--;
	}
}

void MeleeWeapon::use(Map& map, Enemy** enemyArray, int enemyArraySize, int direction, int x, int y) {
	phase = 4;
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