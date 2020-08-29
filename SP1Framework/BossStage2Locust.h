#pragma once
#include "Enemy.h"
#include "Player.h"

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
    BossStage2Locust(int x, int y);
    ~BossStage2Locust();
    
    int update(Map& map, double elapsedTime, Player& player);
    static int getNumberOfLocusts();

    void move(Map& map, double elapsedTime, Player& player);

    void wait(double elapsedTime);
};