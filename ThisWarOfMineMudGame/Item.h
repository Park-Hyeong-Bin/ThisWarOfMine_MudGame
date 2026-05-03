#pragma once
#include <string>
using namespace std;

enum class ItemType { Material, Weapon, Armor, Consumable, ETC };

class Item
{
public:
    string name;
    ItemType type;
    int itemCode;
    
    Item() : name(""), type(ItemType::Material), itemCode(0) {}
    Item(const string &name, const ItemType type, int itemCode = 0) 
        : name(name), type(type), itemCode(itemCode) {}
};