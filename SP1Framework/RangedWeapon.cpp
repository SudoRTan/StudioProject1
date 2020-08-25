#include "RangedWeapon.h"

RangedWeapon::RangedWeapon(){
	setName("Ranged");
	setDamage(1);

	useTime = 0.06;
	lastUseTime = 0.00;

	animationPhases = 1;
	currentAnimationPhase = 0;
	lastAnimateTime = 0;


}
RangedWeapon::~RangedWeapon() {

}

void RangedWeapon::animate(Map& map, double g_dElapsedTime, int direction, int x, int y) {

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

		if (direction == RIGHT)
		{
			
			switch (currentAnimationPhase) {
			case 1:
				map.setTempItem(x + offSet, y + 1, (char)R_POINTING_RIGHT);
				map.setTempItem(x + offSet * 2, y + 1, (char)R_POINTING_RIGHT);
				break;

			default:
				break;
			}
				
		}
		if (direction == LEFT)
		{ 
			switch (currentAnimationPhase){
			case 1:
				map.setTempItem(x + offSet, y + 1, (char)R_POINTING_LEFT);
				map.setTempItem(x + offSet * 2, y + 1, (char)R_POINTING_LEFT);
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


void RangedWeapon::use(Map& map, Enemy** enemyArray, int enemyArraySize, double g_dElapsedTime, int direction, int x, int y) {

	if (g_dElapsedTime - lastUseTime > useTime) {
		lastUseTime = g_dElapsedTime;
		currentAnimationPhase = 3;

		if (direction == LEFT) {
			for (int i = 1; i < 15; i++) {
				Enemy* enemyInRange = getEnemy(x - i, y + 1, enemyArray, enemyArraySize);
				if (enemyInRange != nullptr) {
					enemyInRange->takeDamage(getDamage());
				}

			}

		}

		else if (direction == RIGHT) {
			for (int i = 1; i < 15; i++) {
				Enemy* enemyInRange = getEnemy(x + i, y + 1, enemyArray, enemyArraySize);
				if (enemyInRange != nullptr) {
					enemyInRange->takeDamage(getDamage());
				}
			}
		}
	}
}