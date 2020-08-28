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

    static int numberOfLocusts;

public:
    BossStage2Locust();
    ~BossStage2Locust();
    
    int update(Map& map, double g_dElapsedTime, Player& player);
    static int getNumberOfLocusts();

   // void death(Map& map);

};