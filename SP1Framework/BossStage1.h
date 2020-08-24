#pragma once
#include <vector>
#include "Enemy.h"
#include "BossStage1Fire.h"
class BossStage1 :
    public Enemy
{
public:
    BossStage1();
    ~BossStage1();
protected:
    std::vector<BossStage1Fire*> fireVector;
    static int fireCount;
};