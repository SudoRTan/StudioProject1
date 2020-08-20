#pragma once
#include"Framework/console.h"
#include"Map.h"

class Weapon
{
private:
	int damage;
	std::string name;
	

protected:
	
	int phase;
	void setDamage(int damage);
	void setName(std::string name);

public:

	//constructor & destructor
	Weapon();
	~Weapon();

	int getDamage();
	std::string getName();

	virtual void use(Map& map) = 0;





}; 


