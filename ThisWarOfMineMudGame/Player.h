#pragma once
#include "Character.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Player : public Character
{
    private:
    string name;
    
    vector<int> Inventory;
    
    public:
    Player(const string& name);
    
    //Getters
    string GetName() { return name; }
    vector<int> GetInventory() { return Inventory; }
    
    //기능함수
    void Loot(int cout = 1);
    void UseInventory(vector<int> Inventory);
    void Trade();
};
