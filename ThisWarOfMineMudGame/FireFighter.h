#pragma once
#include "Player.h"

class FireFighter : public Player
{
public:
    static const int F_SIZE = 24;
    FireFighter(const string& name);
};
