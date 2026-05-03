#pragma once
#include "Player.h"

class Deserter : public Player
{
public:
    static const int DESERTER_INVENTORY_SIZE = 15;
    Deserter(const string& name);
};
