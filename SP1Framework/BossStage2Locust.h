#pragma once
#include "Enemy.h"
class BossStage2Locust :
    public Enemy
{
public:
    BossStage2Locust();
    ~BossStage2Locust();


    virtual int update(Map& map, double g_dElapsedTime, Player& player);

    //virtual void death(Map& map);

};