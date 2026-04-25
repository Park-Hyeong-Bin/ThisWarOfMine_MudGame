#include "Player.h"
#include <iostream>
#include <string>
#include <algorithm>
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
        cout << "   4. 무기 부품  -> 체력(50) 회복\n";
        cout << "   5. 떠나기\n";
        cout << "************************************************\n";
        cin >> tradeInput;
        
        //1. 장작 거래(item code = 4,5,6)
        if (tradeInput == 1)
        {
            if (UseInventory(Inventory,4) == true)
            {
                Hp += 10;
                if (Hp > maxHp) Hp = maxHp;
                cout << "좋은 거래 였네.\n";
            }
            else if (UseInventory(Inventory,5) == true)
            {
                Hp += 10;
                if (Hp > maxHp) Hp = maxHp;
                cout << "더 살펴 볼 건 없나?\n";
            }
            else if (UseInventory(Inventory,6) == true)
            {
                Hp += 10;
                if (Hp > maxHp) Hp = maxHp;
                cout << "훌륭하군.\n";
            }
            else{cout << "자네 제대로 들고 있는거 맞나? 제대로 확인하고 거래해주게.\n";}
        }
        
        //2. 음식 거래(item code = 1,2,3)
        else if (tradeInput == 2)
        {
            if (UseInventory(Inventory,1) == true)
            {
                maxHp += 5;
                Hp += 5;
                if (Hp > maxHp) Hp = maxHp;
                cout << "좋은 거래 였네.\n";
            }
            else if (UseInventory(Inventory,2) == true)
            {
                maxHp += 5;
                Hp += 5;
                if (Hp > maxHp) Hp = maxHp;
                cout << "더 살펴 볼 건 없나?\n";
            }
            else if (UseInventory(Inventory,3) == true)
            {
                maxHp += 5;
                Hp += 5;
                if (Hp > maxHp) Hp = maxHp;
                cout << "훌륭하군.\n";
            }
            else{cout << "자네 제대로 들고 있는거 맞나? 제대로 확인하고 거래해주게.\n";}
        }
        
        //3. 의약품 거래(item code = 7,8)
        else if (tradeInput == 3)
        {
            if (UseInventory(Inventory,7) == true)
            {
                power += 5;
                cout << "이런 시기에 없으면 안되는 물건이지.\n";
            }
            else if (UseInventory(Inventory,8) == true)
            {
                power += 5;
                cout << "자네는 정말 훌륭하군.\n";
            }
            else{cout << "이봐 장난은 그만하시게나.\n";} 
        }
        
        //4.무기 부품 거래(item code = 9)
        else if (tradeInput == 4)
        {
            if (UseInventory(Inventory,9) == true)
            {
                Hp += 50;
                if (Hp > maxHp) Hp = maxHp;
                cout << "무기 부품이라니 어디서 구한겐가? 구해다줘서 고맙네.\n";
            }
            else{cout << "그런거로 장난치는거 아닐세.\n";} 
        }
        else if (tradeInput != 5)
        {
            cout << "존재하지 않는 커멘드 입니다.\n";
        }
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
        }
        else
        {
            cout << "현재 아이템이 존재하지 않습니다.\n";
        }
        system("pause");
        system("cls");
    }
    cout << "거래를 하지않고 떠납니다.\n";
    "************************************************\n";
    cout << "거래해줘서 고맙네, 잘 살아보시게나.\n";
    system("pause");
    system("cls");
    
}

void Player::Hospital() 
{
    
    int tradeInput = 0;
    while (tradeInput != 5)
    {
        cout << "************************************************\n";
        cout << "   아이템을 기부합니다.\n";
        cout << "   1. 장작   -> 정신력(4)\n";
        cout << "   2. 음식   -> 정신력(4)\n";
        cout << "   3. 의약품 -> 정신력(7)\n";
        cout << "   4. 무기 부품  -> 정신력(7)\n";
        cout << "   5. 떠나기 -> 치료를 받고 떠납니다.\n";
        cout << "************************************************\n";
        cin >> tradeInput;
        
        //1. 장작 거래(item code = 4,5,6)
        if (tradeInput == 1)
        {
            if (UseInventory(Inventory,4) == true)
            {
                Sanity += 4;
                if (Sanity > maxSanity) Sanity = maxSanity;
                cout << "당신의 기부에 감사합니다.\n";
            }
            else if (UseInventory(Inventory,5) == true)
            {
                Sanity += 4;
                if (Sanity > maxSanity) Sanity = maxSanity;
                cout << "더 기부하실게 있나요?\n";
            }
            else if (UseInventory(Inventory,6) == true)
            {
                Sanity += 4;
                if (Sanity > maxSanity) Sanity = maxSanity;
                cout << "당신덕에 한 사람의 목숨을 더 구할 수 있을 것입니다.\n";
            }
            else{cout << "가지고 있지 않으신거 같습니다. 괜찮습니다.\n";}
        }
        
        //2. 음식 거래(item code = 1,2,3)
        else if (tradeInput == 2)
        {
            if (UseInventory(Inventory,1) == true)
            {
                Sanity += 4;
                if (Sanity > maxSanity) Sanity = maxSanity;
                cout << "환자들이 배부르게 먹을 수 있겠군요.\n";
            }
            else if (UseInventory(Inventory,2) == true)
            {
                Sanity += 4;
                if (Sanity > maxSanity) Sanity = maxSanity;
                cout << "이 음식들 덕에 아이들을 먹일 수 있을거같습니다. 감사합니다.\n";
            }
            else if (UseInventory(Inventory,3) == true)
            {
                Sanity += 4;
                if (Sanity > maxSanity) Sanity = maxSanity;
                cout << "전쟁만 아니였으면 음식이라도 풍족했을 텐데, 당신의 기부에 감사합니다.\n";
            }
            else{cout << "가지고 있지 않으신거 같습니다. 괜찮습니다.\n";}
        }
        
        //3. 의약품 거래(item code = 7,8)
        else if (tradeInput == 3)
        {
            if (UseInventory(Inventory,7) == true)
            {
                power += 7;
                cout << "감사합니다. 이것으로 많은 사람을 살려보겠습니다.\n";
            }
            else if (UseInventory(Inventory,8) == true)
            {
                power += 7;
                cout << "약이군요. 어떻게 구하셨나요?\n";
            }
            else{cout << "가지고 계시지 않는군요. 이런 시기인만큼 이해합니다.\n";} 
        }
        
        //4.무기 부품 거래(item code = 9)
        else if (tradeInput == 4)
        {
            if (UseInventory(Inventory,9) == true)
            {
                Hp += 50;
                if (Hp > maxHp) Hp = maxHp;
                cout << "무기 부품이군요. 이게 있으니 수술을 할 수 있겠군요.\n";
            }
            else
            {
                cout << ">>무기부품이 존재 하지 않습니다.\n";
                cout << "어떤걸 찾고 계시는 건가요?\n";
            } 
        }
        else if (tradeInput != 5)
        {
            cout << "존재하지 않는 커멘드 입니다.\n";
        }
        
        
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
        }
        else
        {
            cout << "현재 아이템이 존재하지 않습니다.\n";
        }
        system("pause");
        system("cls");
    }
    cout << "간단한 치료만 받고 떠납니다. 체력 회복(25)\n";
    Hp+=25;
    "************************************************\n";
    cout << "많은 도움은 되지 못하겠지만, 병원은 언제나 열려있습니다.\n";
    system("pause");
    system("cls");
    
}

void Player::HouseWork()
{
    int AM = 7;
    int HWinput = 0;
    while (AM < 13)
    {
       
        system("pause");
        system("cls");
        cout << "무슨 작업을 하시겠습니까? 현재 시간 : " << AM << endl;
        cout << "(집에서 작업은 12까지 가능합니다.)" << endl;
        cout << "************************************************\n";
        cout << "   아이템을 사용해 정비합니다. 현재체력 : "<< Hp << "현재 정신력 : "<< Sanity<<endl;
        cout << "   1. 휴식       -> 체력 회복(5)\n";
        cout << "   2. 음식 사용  -> 체력 회복(20), 정신력 회복(1)  \n";
        cout << "   3. 장작 사용  -> 체력 회복(5), 정신력 회복(2)  \n";
        cout << "   4. 무기 부품 사용  -> 힘 증가(3), 방어력 증가(1)\n";
        cout << "   5. 약품 사용  -> 체력 회복 (60)\n";
        cout << "   6. 바로 탐색하기\n";
        cout << "************************************************\n";
        cin >> HWinput;
        //1.휴식
        if (HWinput == 1)
        {
            Hp+=5;
            if (Hp > maxHp) Hp = maxHp;
            cout << "휴식을 취합니다. 현재체력 : "<< Hp <<endl;
            system("pause");
        }
        //2.음식사용
        else if (HWinput == 2)
        {
            if (UseInventory(Inventory,1) == true)
            {
                Hp+=20;
                if (Hp > maxHp) Hp = maxHp;
                Sanity+=1;
                if (Sanity > maxSanity) Sanity = maxSanity;
                cout << "음식을 먹습니다. 현재체력 : "<< Hp << "현재 정신력 : "<< Sanity<<endl;
                system("pause");
            }
            else if (UseInventory(Inventory,2) == true)
            {
                Hp+=20;
                if (Hp > maxHp) Hp = maxHp;
                Sanity+=1;
                if (Sanity > maxSanity) Sanity = maxSanity;
                cout << "음식을 먹습니다. 현재체력 : "<< Hp << "현재 정신력 : "<< Sanity<<endl;
                system("pause");
            }
            else if (UseInventory(Inventory,3) == true)
            {
                Hp+=20;
                if (Hp > maxHp) Hp = maxHp;
                Sanity+=1;
                if (Sanity > maxSanity) Sanity = maxSanity;
                cout << "음식을 먹습니다. 현재체력 : "<< Hp << "현재 정신력 : "<< Sanity<<endl;
                system("pause");
            }
            else
            {
                cout<< "해당 아이템이 존재 하지 않습니다.\n";
                system("pause");
            }
        }
        
        //3.장작 사용
        else if (HWinput == 3)
        {
            
            if (UseInventory(Inventory,4)==true)
            {
                Hp+=5;
                if (Hp > maxHp) Hp = maxHp;
                Sanity+=2;
                if (Sanity > maxSanity) Sanity = maxSanity;
                cout << "장작을 이용해 몸을 따뜻하게 합니다. 현재체력 : "<< Hp << "현재 정신력 : "<< Sanity<<endl;
                system("pause");
            }
            else if (UseInventory(Inventory,5)==true)
            {
                Hp+=5;
                if (Hp > maxHp) Hp = maxHp;
                Sanity+=2;
                if (Sanity > maxSanity) Sanity = maxSanity;
                cout << "장작을 이용해 몸을 따뜻하게 합니다. 현재체력 : "<< Hp << "현재 정신력 : "<< Sanity<<endl;
                system("pause");
            }
            else if (UseInventory(Inventory,6) == true)
            {
                Hp+=5;
                if (Hp > maxHp) Hp = maxHp;
                Sanity+=2;
                if (Sanity > maxSanity) Sanity = maxSanity;
                cout << "장작을 이용해 몸을 따뜻하게 합니다. 현재체력 : "<< Hp << "현재 정신력 : "<< Sanity<<endl;
                system("pause");
            }
            else
            {
                cout<< "해당 아이템이 존재 하지 않습니다.\n";
                system("pause");
            }
        }
        
        //4.무기 부품 사용
        else if (HWinput == 4)
        {
            
            if (UseInventory(Inventory,9))
            {
                power += 3;
                guard += 1;
                cout << "무기 부품을 사용하여, 사용중인 장비들을 정비합니다. 현재 힘 : "<<power << "현재 방어력 : "<<guard <<endl;
                system("pause");
            }
            else
            {
                cout<< "해당 아이템이 존재 하지 않습니다.\n";
                system("pause");
            }
        }
        
        //5. 의약품 사용
        else if (HWinput == 5)
        {
            
            if (UseInventory(Inventory,7))
            {
                Hp+=60;
                if (Hp > maxHp) Hp = maxHp;
                cout << "의약품을 사용하여 치료를 합니다. 현재체력 : "<< Hp<<endl;
                system("pause");
            }
            else if (UseInventory(Inventory,8))
            {
                Hp+=60;
                if (Hp > maxHp) Hp = maxHp;
                cout << "의약품을 사용하여 치료를 합니다. 현재체력 : "<< Hp<<endl;
                system("pause");
            }
            else
            {
                cout<< "해당 아이템이 존재 하지 않습니다.\n";
                system("pause");
            }
        }
        
        //나가기
        else if (HWinput == 6)
        {
            cout << "바로 탐색하러 나갑니다.";
            system("pause");
            AM = 13;
        }
        
        //오류
        else
        {
            cout << "존재하지 않는 커멘드 입니다.\n";
        }
        AM++;
        
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
        }
        else
        {
            cout << "현재 아이템이 존재하지 않습니다.\n";
        }
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

bool Player::UseInventory(vector<int>& Inventory, int item_Code)
{
    auto it = find(Inventory.begin(), Inventory.end(), item_Code);
    if (it != Inventory.end())
    {
        Inventory.erase(it);
        
        return true;
    }
    else
    {
        return false;
    }
    
}