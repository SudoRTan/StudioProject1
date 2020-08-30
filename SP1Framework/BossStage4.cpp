#include "BossStage4.h"

BossStage4::BossStage4(Player* player) : Stage(player), knifeMan(KNIFEMAN), gunMan(GUNMAN)
{
	playerMaxHealth = player->getHealth();
	once = false;
}

BossStage4::~BossStage4()
{

}

void BossStage4::update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, int& gameState)
{
	if (!once) {
		gunMan.init(*map);
		knifeMan.init(*map);
		once = true;
	}
	else if (player->getHealth() > playerMaxHealth / 2) {
		gunMan.update(*map, g_dElapsedTime, *player);
	}
	else if (player->getHealth() <= playerMaxHealth / 2 && player->getHealth() > 0) {
		knifeMan.update(*map, g_dElapsedTime, *player);
	}
	else if (player->getHealth() <= 0) {
		gameState = APRIL_FOOLS_MENU;
	}
}