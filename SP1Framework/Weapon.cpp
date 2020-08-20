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


/*
void Weapon::use(Map& map) {

}

*/