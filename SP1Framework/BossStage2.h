#pragma once
#include "Stage.h"
#include "BossStage2Locust.h"

class BossStage2 :
    public Stage
{
private:
    Enemy** locusts;
    int numberOfLocusts;
    int locustLeft;

public:
    BossStage2(Player* player);
    ~BossStage2();

    void update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, int& gameState);

};