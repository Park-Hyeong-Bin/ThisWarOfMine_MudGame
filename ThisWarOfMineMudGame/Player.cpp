#include "Player.h"

Player::Player(const string& name)
    :Character(25,25,15,0),
    name(name)
{
    Hp = maxHp;
    Sanity = maxSanity;
    attackDamage = power * 0.5f;
    
}

void Player::Loot(int count)
{
      
    //count가 아이템을 vector에 추가
    cout << "************************************************\n";
    cout << "        아이템을 탐색합니다.! \n";
    cout << "************************************************\n";
    system("pause");
    system("cls");
    cout << "************************************************\n";
    cout << "         현재 내 인벤토리 \n";
    cout << "************************************************\n";
    for (int i = 0; i < count; i++)
    {
        //랜덤 숫자 1개씩 인벤토리 벡터에 넣음
        int Item = rand()%15 + 1;
        if (Item < 10)
        {
            Inventory.push_back(Item);
        }
        else
        {
            cout << "아무것도 발견하지 못했습니다...\n";
        }
    }
    if (Inventory.size() > 0)
    {
        for (int i = 0; i < Inventory.size(); i++)
        {
            string itemName;
            if (Inventory[i]== 1 ||Inventory[i]== 2 ||Inventory[i]== 3 ) itemName = "음식";
            else if (Inventory[i] == 4|| Inventory[i] == 5||Inventory[i] == 6) itemName = "장작";
            else if (Inventory[i] == 7) itemName = "의약품";
            else if (Inventory[i] == 8) itemName = "의약품";
            else if (Inventory[i] == 9) itemName = "무기";
            else itemName = "None";
            cout << "> Slot" << to_string(i+1) << "[" << itemName << "]\n";
        }
    }
    else
    {
        cout << "현재 아이템이 존재하지 않습니다.\n";
    }
}

void Player::Trade() const
{
    
    int tradeInput = 0;
    while (tradeInput != 5)
    {
        cout << "************************************************\n";
        cout << "   아이템을 사용해 거래합니다.\n";
        cout << "   1. 장작   -> 체력회복(30)\n";
        cout << "   2. 음식   -> 체력 단련(최대체력 5 증가)\n";
        cout << "   3. 의약품 -> 힘 단련(힘 5 증가)\n";
        cout << "   4. 무기   -> 체력, 정신력 최대로 회복\n";
        cout << "   5. 떠나기\n";
        cout << "************************************************\n";
        cin >> tradeInput;
        
        if (tradeInput == 1)
        {
            Hp += 30;
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
            Hp = maxHp;
            Sanity = maxSanity;
        }
        else
        {
            cout << "존재하지 않는 커멘드 입니다.\n";
        }
    }
    
    
    
}
