#pragma once
#include <vector>
#include "Stage.h"
#include "Enemy.h"
#include "BossStage1Fire.h"
class BossStage1 :
    public Stage
{
private:
    std::vector<BossStage1Fire*> fireVector;
    bool playerOnFire;
    double lastSpawnTime;
    double timer;
    //void checkPlayerPosition(Player player, double g_dElapsedTime);

    Enemy** fire;

  //  int currNumberOfFires;

    int maxNumberOfFires;

public:
    BossStage1(Player* player, double g_dElapsedTime);
    ~BossStage1();
    void update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, int& gameState);

};