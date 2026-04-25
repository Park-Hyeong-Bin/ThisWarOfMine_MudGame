#pragma once
#include "Character.h"
#include <string>
using namespace std;


class Enemy : public Character
{
    private:
    string name;
    int rewrad;
public:
    Enemy(const string &name, int hp, int sanity, int power, int guard, int rewrad);
    
    string GetName() const{return name;}
    int GetRewrad() const{return rewrad;}
};
