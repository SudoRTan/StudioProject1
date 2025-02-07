#include "Weapon.h"

Weapon::Weapon()
{   
	useTime = 0;
	lastUseTime = 0;
	lastAnimateTime = 0;
	damage = 1;
	currentAnimationPhase = 0;
	currentAmmo = 0;
	maxAmmo = 0;
	animationPhases =  0;
}

Weapon::~Weapon()
{

}


void Weapon::setDamage(int damage) {
	this->damage = damage;
}


void Weapon::setName(std::string name) {
	this->name = name;
}


int Weapon::getDamage() {
	return damage;
}
std::string Weapon::getName() {
	return name;
}

int Weapon::getAmmo()
{
	if (maxAmmo == 0) {
		return -1;
	}
	else
	{
		return currentAmmo;
	}
}

void Weapon::replenishAmmo() {
	currentAmmo = maxAmmo;
}

void Weapon::update(Map& map, Enemy** enemyArray, int enemyArraySize, double elapsedTime, int direction, int x, int y, bool attacking) {
	//use(map, enemyArray, enemyArraySize, elapsedTime, direction, x, y);
	//animate(map, elapsedTime, direction, x, y);

}

/*
void Weapon::use(Map& map) {

}

*/