#include "RangedWeapon.h"

RangedWeapon::RangedWeapon(){
	setName("Ranged");
	setDamage(10);

	useTime = ;
	lastUseTime = 0.00;

	animationPhases = 3;
	currentAnimationPhase = 0;
	lastAnimateTime = 0;


}
