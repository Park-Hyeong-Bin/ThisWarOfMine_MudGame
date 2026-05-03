#pragma once
#include "Character.h"
#include <string>
#include <vector>

#include "EnemyDB.h"
#include "Item.h"
using namespace std;


class Enemy : public Character
{
    private:
    string name;
    vector<int> dropPool;
public:
    Enemy(const string& name, const EnemyDB& data);
    
    string GetName() const{return name;}
    
    virtual string GetAttackMessage() const {return "";}
    virtual int Drop() const;
};
