#include <iostream>
#include "UI.h"
#include "Entity.h"
using namespace std;


void UI::MaxHealth()
{
	int Maxhealth = 100;

};
	
/*int UI::HealthReduce()
{

	int HealthRemaining = - 2;
};*/

UI::UI()
{
	
}


UI::~UI()
{
 
}

int UI::HealthBar(Player& player)
{
	cout << "Health:";

	float ShowHealth = player.getHealth() / 10;
	float HiddenHealth = 10 - ShowHealth;
	
	{
		for (int i = 0; i < int(ShowHealth); i++);
		cout << '[0]';
		for (int i = 0; i < int(HiddenHealth); i++);
		cout << '[]';

	};

};