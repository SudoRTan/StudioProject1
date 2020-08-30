#pragma once
#include "Player.h"
class BossStage5Player :
    public Player
{
public:
    BossStage5Player();
    ~BossStage5Player();
    int update(Map& map, SKeyEvent KeyEvent[K_COUNT], double g_dElapsedTime, Enemy** enemyArray, int enemyArraySize, Collectible** collectibleArray, int collectibleArraySize);
};