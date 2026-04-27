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
    int GetHp() const {return Hp;}
    int GetMaxHp() const {return maxHp;}
    int GetSanity() const {return Sanity;}
    int GetMaxSanity() const {return maxSanity;}
    int GetDamage() const {return power*0.5f;}
    //기능 함수
    bool isAlive() const { return (Hp > 0 && Sanity > 0);}
    void TakeDamage(int damage);
    virtual int Attack() const;
    void SetHp();
};
