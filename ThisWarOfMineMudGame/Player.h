#pragma once
#include "Character.h"
#include <string>
#include <iostream>
#include <vector>

#include "Item.h"
using namespace std;

class Player : public Character
{
    private:
    string name;
    string className;
    int I_Size;
    vector<Item> Inventory;
    
    
    public:
    Player(const string& name);
    Player(const string& name, const string& className);
    
    //소멸자
    virtual ~Player();
    
    protected:
    //자식 클래스(소방관, 탈영군인, 수집가)의 스탯을 직접 지정할때 사용되는 생성자
    Player(const string& name, const string& className,
        int hp, int san, int pow, int gua, int s);
    void AddItem(const Item& item) {
        Inventory.push_back(item);
    }
    
    
    public:
    //Getters
    string GetName() { return name; }
    vector<Item> GetInventory() { return Inventory; }
    
    //기능함수
    void Loot(); // 랜덤 아이템 3개 획득 (Material, Consumable, ETC 타입 위주)
    void Loot(Item item); // 특정 아이템 획득
    
    
    bool UseInventory(vector<Item>& inv, int item_Code);
    void Trade();
    void Hospital();
    void HouseWork();
    void NewDay();
    
    void SortInventory(); // 인벤토리 이름순 정렬
    void PrintInventory() const; // 인벤토리 전체 출력
};
