#include "Enemy.h"
#include "Character.h"
#include <iostream>

using namespace std;

Enemy::Enemy(const string& name, int hp, int sanity ,int power, int guard, int rewrad)
: Character(hp,sanity,power,guard),
name(name), rewrad(rewrad)
{
    attackDamage = power * 0.5f;
}

