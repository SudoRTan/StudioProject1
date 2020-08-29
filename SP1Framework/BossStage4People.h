#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Projectile.h"

enum
{
    GUNMAN,
    KNIFEMAN
};

class BossStage4People :
    public Enemy
{
public:
    BossStage4People();
    ~BossStage4People();
    int update(Map& map, double g_dElapsedTime, Player& player);
private:
    static int personCount;
    int personType;
    Projectile* projectile[2];
    double lastMoveTime;
};