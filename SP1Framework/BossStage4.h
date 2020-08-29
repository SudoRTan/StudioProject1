#pragma once
#include "Stage.h"
#include "BossStage4People.h"
class BossStage4 :
    public Stage
{
public:
    BossStage4(Player* player);
    ~BossStage4();
private:
    void update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, int& gameState);
    Enemy** enemies;
};