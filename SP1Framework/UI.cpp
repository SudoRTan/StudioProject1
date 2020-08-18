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

void UI::HealthBar(Console& console,Player& player)
{
	console.writeToBuffer(0,1, (char)48, 'HP');

	float ShowHealth = player.getHealth() / 10;
	float HiddenHealth = 10 - ShowHealth;
	
	{
		for (int i = 0; i < int(ShowHealth); i++);
		console.writeToBuffer(6,1,(char)48,'[0]');
		for (int i = 0; i < int(HiddenHealth); i++);
		console.writeToBuffer(6,1,(char)48,'[]');

	};

};

void Weapons::AmmoCounter(Console& console)
{
	console.writeToBuffer(0,2,(char)48, 'Ammo');
	float ShowAmmo = Weapons::getAmmo() / 10;
	float HiddenAmmo = 10 - ShowAmmo;
	{
		for (int i = 0; i < int(ShowAmmo); i++);
		console.writeToBuffer(6,2,char(48),'[0]');
		for (int i = 0; i < int(HiddenAmmo); i++);
		console.writeToBuffer(6,2,char(48), '[]');

	}
	
}