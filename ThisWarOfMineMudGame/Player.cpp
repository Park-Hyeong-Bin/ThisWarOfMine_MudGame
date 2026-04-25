#include "Player.h"
#include <iostream>
#include <string>
using namespace std;

Player::Player(const string& name)
    :Character(50,25,20,0),
    name(name)
{
    Hp = maxHp;
    Sanity = maxSanity;
    attackDamage = power * 0.5f;
    
}

void Player::Loot(int count)
{
    if (count == 0) {
    cout<<"그는 아무것도 가지고 있지 않았습니다.";
    }
    
    //count가 아이템을 vector에 추가
    cout << "************************************************\n";
    cout << "        아이템을 탐색합니다.! \n";
    cout << "************************************************\n";
    system("pause");
    for (int i = 0; i < count; i++)
    {
        //랜덤 숫자 1개씩 인벤토리 벡터에 넣음
        int Item = rand()%15 + 1;
        if (Item < 10)
        {
            string itemName;
            if (Item == 1 || Item == 2 || Item == 3) itemName = "음식";
            else if (Item == 4 || Item == 5 ||Item == 6) itemName = "장작";
            else if (Item == 7 || Item == 8) itemName = "의약품";
            else if (Item == 9) itemName = "무기 부품";
            else itemName = "None";
            cout << ">>아이템을 발견했습니다! [" << itemName << "]\n";
            Inventory.push_back(Item);
        }
        else
        {
            cout << "아무것도 발견하지 못했습니다...\n";
        }
    }
    system("pause");
    system("cls");
    cout << "************************************************\n";
    cout << "         현재 내 인벤토리 \n";
    cout << "************************************************\n";
    if (Inventory.size() > 0)
    {
        for (int i = 0; i < Inventory.size(); i++)
        {
            string itemName;
            if (Inventory[i] == 1 || Inventory[i] == 2 || Inventory[i] == 3) itemName = "음식";
            else if (Inventory[i] == 4 || Inventory[i] == 5 || Inventory[i] == 6) itemName = "장작";
            else if (Inventory[i] == 7 || Inventory[i] == 8) itemName = "의약품";
            else if (Inventory[i] == 9) itemName = "무기 부품";
            else itemName = "None";
            cout << "> Slot" << to_string(i+1) << "[" << itemName << "]\n";
        }
        system("pause");
        system("cls");  
    }
    else
    {
        cout << "현재 아이템이 존재하지 않습니다.\n";
        system("pause");
        system("cls");
    }
}

void Player::Trade() 
{
    
    int tradeInput = 0;
    while (tradeInput != 5)
    {
        cout << "************************************************\n";
        cout << "   아이템을 사용해 거래합니다.\n";
        cout << "   1. 장작   -> 체력회복(10)\n";
        cout << "   2. 음식   -> 체력 단련(최대체력 5 증가)\n";
        cout << "   3. 의약품 -> 무기 정비(힘 3 증가)\n";
        cout << "   4. 무기   -> 체력(50) 회복\n";
        cout << "   5. 떠나기\n";
        cout << "************************************************\n";
        cin >> tradeInput;
        
        if (tradeInput == 1)
        {
            Hp += 10;
            if (Hp > maxHp) Hp = maxHp;
        }
        else if (tradeInput == 2)
        {
            maxHp += 5;
            Hp += 5;
            if (Hp > maxHp) Hp = maxHp;
        }
        else if (tradeInput == 3)
        {
            power += 5;
        }
        else if (tradeInput == 4)
        {
            Hp += 50;
            if (Hp > maxHp) Hp = maxHp;
        }
        else if (tradeInput != 5)
        {
            cout << "존재하지 않는 커멘드 입니다.\n";
        }
        system("pause");
        system("cls");
    }
    cout << "거래를 하지않고 떠납니다.\n";
    system("pause");
    system("cls");
    
}

void Player::HouseWork()
{
    int AM = 7;
    int HWinput = 0;
    while (AM < 13)
    {
        system("cls");
        cout << "무슨 작업을 하시겠습니까? 현재 시간 : " << AM << endl;
        cout << "(집에서 작업은 12까지 가능합니다.)" << endl;
        cout << "************************************************\n";
        cout << "   아이템을 사용해 정비합니다. 현재체력 : "<< Hp << "현재 정신력 : "<< Sanity<<endl;
        cout << "   1. 휴식       -> 체력 회복(5)\n";
        cout << "   2. 음식 사용  -> 체력 회복(20), 정신력 회복(3)  \n";
        cout << "   3. 장작 사용  -> 체력 회복(5), 정신력 회복(3)  \n";
        cout << "   4. 무기 부품 사용  -> 힘 증가(3), 방어력 증가(1)\n";
        cout << "   5. 약품 사용  -> 체력 회복 (60)\n";
        cout << "   6. 바로 탐색하기\n";
        cout << "************************************************\n";
        cin >> HWinput;
        
        if (HWinput == 1)
        {
            Hp+=5;
            if (Hp > maxHp) Hp = maxHp;
            cout << "휴식을 취합니다. 현재체력 : "<< Hp <<endl;
            system("pause");
        }
        else if (HWinput == 2)
        {
            Hp+=20;
            if (Hp > maxHp) Hp = maxHp;
            Sanity+=1;
            if (Sanity > maxSanity) Sanity = maxSanity;
            cout << "음식을 먹습니다. 현재체력 : "<< Hp << "현재 정신력 : "<< Sanity<<endl;
            system("pause");
        }
        else if (HWinput == 3)
        {
            Hp+=5;
            if (Hp > maxHp) Hp = maxHp;
            Sanity+=3;
            if (Sanity > maxSanity) Sanity = maxSanity;
            cout << "장작을 이용해 몸을 따뜻하게 합니다. 현재체력 : "<< Hp << "현재 정신력 : "<< Sanity<<endl;
            system("pause");
        }
        else if (HWinput == 4)
        {
           power += 3;
            guard += 1;
            cout << "무기 부품을 사용하여, 사용중인 장비들을 정비합니다. 현재 힘 : "<<power << "현재 방어력 : "<<guard <<endl;
            system("pause");
        }
        else if (HWinput == 5)
        {
            Hp+=60;
            if (Hp > maxHp) Hp = maxHp;
            cout << "의약품을 사용하여 치료를 합니다. 현재체력 : "<< Hp<<endl;
            system("pause");
        }
        else if (HWinput == 6)
        {
            cout << "바로 탐색하러 나갑니다.";
            system("pause");
            AM = 13;
            
        }
        else
        {
            cout << "존재하지 않는 커멘드 입니다.\n";
        }
        AM++;
    }
    
    cout << "13시가 되어 바로 탐색하러 나갑니다.";
    
    
    
}

void Player::NewDay()
{
    cout << "탐색 횟수를 전부 소진하였습니다.\n";
    Hp -= 5;
    Sanity -= 5;
    cout << "새로운 날이 밝았습니다.(체력 -5, 정신력 -5)\n";
    cout << "현재 체력 : " << Hp << "현재 정신력 : "<< Sanity << endl; 
    system("pause");
    system("cls");
}