#include "Character.h"
#include <iostream>

using namespace ::std;

//외부 입력 값 세팅 초기화
Character::Character(int hp, int sanity, int power, int guard)
    : maxHp(hp), maxSanity(sanity), power(power), guard(guard)
{
    Hp = maxHp;
    Sanity = maxSanity;
    attackDamage = power * 0.5f;
}

//기능 함수
void Character::TakeDamage(int damage)
{
    int FinalDamage = damage-guard;
    Hp -= FinalDamage;
    cout << FinalDamage;
    if (Hp < 0) Hp = 0;
}

int Character::Attack() const
{
    return (int)attackDamage;
}
