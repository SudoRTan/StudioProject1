#pragma once
#include <vector>
#include "Stage.h"
#include "Enemy.h"
#include "BossStage1Fire.h"
class BossStage1 :
    public Stage
{
private:
    bool playerOnFire;
    double lastSpawnTime;
    double timer;

    Enemy** fire;

    int maxNumberOfFires;

public:
    BossStage1(Player* player, double g_dElapsedTime);
    ~BossStage1();

    void update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, int& gameState);

};