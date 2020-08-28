#pragma once
#include "Stage.h"
#include "Enemy.h"
#include "BossStage3Virus.h"
class BossStage3 :
    public Stage
{
public:
    BossStage3(Player* player);
    ~BossStage3();
    void update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, int& gameState);
private:
    Enemy** virus;
    int numberOfVirus;
    int maxNumberOfVirus;
};