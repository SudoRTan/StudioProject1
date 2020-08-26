#pragma once
#include"Framework/console.h"
#include"Map.h"
#include "Enemy.h"

class Weapon
{
private:
	int damage;
	std::string name;
	

protected:
	void setDamage(int damage);
	void setName(std::string name);

	double useTime;
	double lastUseTime;

	// Animation variables
	int animationPhases;
	int currentAnimationPhase;
	double lastAnimateTime;


public:

	//constructor & destructor
	Weapon();
	~Weapon();

	int getDamage();
	std::string getName();

	virtual void animate(Map& map, double elapsedTime, int direction, int x, int y) = 0;
	
	virtual void use(Map& map, Enemy** enemyArray, int enemyArraySize, double elapsedTime, int direction, int x, int y) = 0;


	virtual void update(Map& map, Enemy** enemyArray, int enemyArraySize, double elapsedTime, int direction, int x, int y, bool attacking);


}; 


