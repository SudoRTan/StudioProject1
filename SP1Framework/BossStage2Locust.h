#pragma once
#include "Enemy.h"

enum LOCUST_GAME_STATE {
    LOCUST_MOVING,
    LOCUST_WAITING,
    NEW_LOCATION
};

class BossStage2Locust :
    public Enemy
{
private:
    int timeStartedWaiting;
    int currentState;

    int futureX;
    int futureY;


public:
    BossStage2Locust();
    ~BossStage2Locust();


    int update(Map& map, double g_dElapsedTime, Player& player);

   // void death(Map& map);

};