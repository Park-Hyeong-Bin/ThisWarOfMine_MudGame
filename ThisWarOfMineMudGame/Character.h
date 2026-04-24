#pragma once

class Character
{
    protected:
    //기본 능력치
    int power;
    int guard;
    int maxHp, maxSanity;
    
    //파생능력치
    int Hp, Sanity;
    float attackDamage;
    
    public:
    Character(int hp, int sanity, int power, int guard);
    virtual ~Character(){}
    
    //Getter
    int GetHp();
    int GetMaxHp();
    int GetSanity();
    int GetMaxSanity();
    //기능 함수
    bool isAlive() const { return (Hp > 0 && Sanity > 0); }
    void TakeDamage(int damage);
    virtual int Attack() const;
};
