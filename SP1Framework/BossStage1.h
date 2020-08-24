#pragma once
#include <vector>
#include "Stage.h"
#include "Enemy.h"
#include "BossStage1Fire.h"
class BossStage1 :
    public Stage
{
public:
    BossStage1();
    ~BossStage1();
    static int fireCount;
    void update(); //change to updateStage
private:
    std::vector<BossStage1Fire*> fireVector;
};