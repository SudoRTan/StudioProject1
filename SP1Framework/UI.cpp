#include "UI.h"
#include "Entity.h"
#include <iostream>
using namespace std;


void UI::MaxHealth()
{
	int Maxhealth = 100;

};
	
int UI::HealthReduce(Player& player)
{

	int health = player.getHealth() - 2;
	return health;
};

UI::UI()
{
	
}


UI::~UI()
{
 
}

void UI::HealthBar(Console& console,Player& player)
{
	console.writeToBuffer(0,0, (char)48, 'HP:');

	float ShowHealth = player.getHealth() / 10;
	float HiddenHealth = 10 - ShowHealth;
	
	{
		for (int i = 0; i < int(ShowHealth); i++);
		console.writeToBuffer(6,0,(char)48,'[0]');
		for (int i = 0; i < int(HiddenHealth); i++);
		console.writeToBuffer(6,0,(char)48,'[ ]');

	};

};

