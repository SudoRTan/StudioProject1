#pragma once
#include "Position.h"
#include "Map.h"
#include "createArray.h"

enum ENTITY_STATE {
	NO_CHANGE,
	PLAYER_REACHED_DOOR,
	PLAYER_GOT_HEALTH
	
};


enum DIRECTION {
	LEFT,
	RIGHT,
	UP,
	DOWN
};

class Entity
{

protected:
	Position position;
	int health;
	int maxHealth;
	int damage;
	int canJump;
	int direction;


	double lastJumpTime;
	double lastMovementTime;
	double updateDelay;

	double damageDelay;
	double lastDamageTime;

	// Variables to store 2d Entites
	int height;
	int width;
	char** symbolArray;


	void setHealth(int newHealth);
	void setDamage(int newDamage);

	void updateNewPosition(Map& map, int newX, int newY);

public:
	Entity();
	~Entity();
	int getPositionX();
	int getPositionY();
	int getHealth();
	int getDamage();

	void takeDamage(int damage, double g_dElapsedTime);
	void takeDamage(int damage);

	bool isLocatedAt(int x, int y);

	bool canEntityMove(Map& map, int x, int y);

	bool onSolidFloor(Map& map, int x, int y);

	bool hangingOnEdge(Map& map, int x, int y);

	int getDirection();

	void resetHealth();

	void cleanUp();
	virtual void death(Map& map);
};