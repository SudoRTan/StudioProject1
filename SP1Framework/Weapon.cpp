#include "Weapon.h"

Weapon::Weapon()
{   
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


void Weapon::update(Map& map, Enemy** enemyArray, int enemyArraySize, double elapsedTime, int direction, int x, int y, bool attacking) {
	//use(map, enemyArray, enemyArraySize, elapsedTime, direction, x, y);
	//animate(map, elapsedTime, direction, x, y);

}

/*
void Weapon::use(Map& map) {

}

*/