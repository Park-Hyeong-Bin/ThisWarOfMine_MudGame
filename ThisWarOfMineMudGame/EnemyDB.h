#pragma once
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct EnemyDB
{
    int hp, san, pow, gua;
    vector<int> dropPool;
};

unordered_map<string, EnemyDB> createEnemyDB();
