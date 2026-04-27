#pragma once
#include "Player.h"
#include "Enemy.h"
class Route
{
    
    public:
    //루트 기본 세팅
    int routCount;
    
    Route(int routeCount);
    void RandomEvent(int routeCount, Player& player,Enemy& enemy);
    bool Battle(Player& player,Enemy& enemy);
    void ExploreMap(Player& player, Enemy& enemy, int routeType);
    
};
