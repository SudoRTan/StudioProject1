#include "RangedWeapon.h"

RangedWeapon::RangedWeapon(){
	setName("Ranged");
	setDamage(1);

	maxAmmo = 20;
	currentAmmo = 20;

	useTime = 0.06;
	lastUseTime = 0.00;

	animationPhases = 1;
	currentAnimationPhase = 0;
	lastAnimateTime = 0;

	bullet = nullptr;


}
RangedWeapon::~RangedWeapon() {

}

void RangedWeapon::animate(Map& map, double elapsedTime, int direction, int x, int y) {

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

		if (elapsedTime - lastAnimateTime > (useTime / animationPhases)) {
			lastAnimateTime = elapsedTime;
			currentAnimationPhase--;
		}
	}
}


void RangedWeapon::use(Map& map, Enemy** enemyArray, int enemyArraySize, double elapsedTime, int direction, int x, int y) {

	if ((elapsedTime - lastUseTime > useTime) && (currentAmmo != 0)) {
		lastUseTime = elapsedTime;
		currentAnimationPhase = 3;
		currentAmmo--;

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
			

		if (bullet == nullptr) {
			bullet = new Projectile(x, y, direction);
		}
		
	}
		PlaySound(TEXT("./Sounds/gunFiring.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}
}

void RangedWeapon::update(Map& map, Enemy** enemyArray, int enemyArraySize, double elapsedTime, int direction, int x, int y, bool attacking) {
	if (attacking) {
		use(map, enemyArray, enemyArraySize, elapsedTime, direction, x, y);
	}
	if (bullet != nullptr) {
		if (bullet->getHealth() == 0) {
			bullet->death(map);
			delete bullet;
			bullet = nullptr;
		}
		else {
			bullet->update(map, elapsedTime, enemyArray, enemyArraySize);
		}
	}
	animate(map, elapsedTime, direction, x, y);

}