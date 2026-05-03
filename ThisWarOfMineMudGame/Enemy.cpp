#include "Enemy.h"
#include "Character.h"
#include <iostream>

using namespace std;

Enemy::Enemy(const string& name, const EnemyDB& data) 
: Character(data.hp, data.san, data.pow, data.gua)
, name(name), dropPool(data.dropPool)
{}


int Enemy::Drop() const
{
    //전투에서 승리시 적이 가지고있는 아이템 중 하나를 랜덤하게 제공
    if (dropPool.empty()) return -1; // 풀이 없을 경우
    return dropPool[rand() % dropPool.size()];
}

