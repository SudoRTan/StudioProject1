#pragma once
#include"Framework/console.h"
#include "Player.h"
#include"Map.h"

class Weapon
{
private:
	int damage;
	std::string name;

protected:
	void setDamage(int damage);
	void setName(std::string name);

public:

	Weapon();
	~Weapon();

	int getDamage();
	std::string getName();

	virtual void use(Map& map) = 0;




	//constructor & destructor

}; 


