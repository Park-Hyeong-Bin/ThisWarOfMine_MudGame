#pragma once
#include "Player.h"

class Collector : public Player
{
public:
    static const int COLLECTOR_INVENTORY_SIZE = 30;
    Collector(const string& name);
};
