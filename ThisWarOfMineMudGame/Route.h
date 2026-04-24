#pragma once
#include "Player.h"
class Route
{
    
    public:
    //루트 기본 세팅
    int routCount;
    
    Route(int routeCount);
    void RandomEvent(int routeCount, Player& player);
    
    
};
