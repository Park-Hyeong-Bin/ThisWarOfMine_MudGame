#include "Deserter.h"

#include "ItemData.h"

Deserter::Deserter(const string& name)
    : Player(name, "Deserter", 90, 50, 50, 0, DESERTER_INVENTORY_SIZE)
{}
