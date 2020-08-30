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
    BossStage4People(int type);
    ~BossStage4People();
    int update(Map& map, double g_dElapsedTime, Player& player);

private:
    int personType;
    int shotsFired;
    Projectile* projectile;
};