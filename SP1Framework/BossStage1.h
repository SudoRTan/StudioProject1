#pragma once
#include <vector>
#include "Stage.h"
#include "Enemy.h"
#include "BossStage1Fire.h"
class BossStage1 :
    public Stage
{
public:
    BossStage1(Player* player);
    ~BossStage1();
    static int fireCount;
    void update(SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, int& gameState);
private:
    std::vector<BossStage1Fire*> fireVector;
    bool playerOnFire;
    double lastSpawnTime;
    void spawnFire(double g_dElapsedTime);
    void checkPlayerPosition(Player player, double g_dElapsedTime);
};