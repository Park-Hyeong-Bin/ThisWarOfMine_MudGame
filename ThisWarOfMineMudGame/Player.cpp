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
        else
        {
            cout << "존재하지 않는 커멘드 입니다.\n";
        }
    }
    
    
    
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
        cout << "   아이템을 사용해 거래합니다.\n";
        cout << "   1. 휴식       -> 체력 회복(5), 정신력 회복(1)\n";
        cout << "   2. 음식 사용  -> 체력 회복(20), 정신력 회복(3)  \n";
        cout << "   3. 장작 사용  -> 체력 회복(5), 정신력 회복(3)  \n";
        cout << "   4. 무기 사용  -> 힘 5 증가\n";
        cout << "   5. 약품 사용  -> 체력 회복 (60)\n";
        cout << "   6. 바로 탐색하기\n";
        cout << "************************************************\n";
        cin >> HWinput;
        
        if (HWinput == 1)
        {
            Hp+=5;
            if (Hp > maxHp) Hp = maxHp;
            Sanity+=1;
            if (Sanity > maxSanity) Sanity = maxSanity;
            cout << "휴식을 취합니다. 현재체력 : "<< Hp<<endl;
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
           power += 5;
            cout << "무기 부품을 사용하여, 사용중인 무기들을 정비합니다. 현재 힘 : "<<power<<endl;
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

/*
* 클래스 정의
상속 시켜야 함
vector 사용 -> 예시 아이템

-------------------
위 3개의 요구사항에 맞는 본인이 좋아하는 캐릭터가 등장하는
RPG 등 게임을 만들어 보기

----------------------
제출
구글문서로 github주소, 플레이 영상주소
------------------------
제출 github 주소와 시연 영상
1.블로그에 본인 프로젝트에 대한 설명(이게 어떤 코드인지)
예시) 이부분은 전투입니다. 
+복습하면서, 구현하면서 오류 또는 이해가 어려웠던 부분
이걸 어떻게 해결했고, 어떤게 해결방안이었고 결과는 어떻게 되었는지.


내가 만들게임(디스워오브마인 머드게임버전)
- 필요 생성자
- 캐릭터(플레이어, 적, 거래npc), 지역(집, 안전한 탐사지, 위험한 탐사지)
- 물건관련
- 필요 행동(탐색, 전투, 출발, 귀환, 집에서 행동)
-탐색( 물건획득, 아무것도 없음, npc조우, 적 조우, 귀환) (총 5턴) (6턴이 되면 강제 귀가)
- npc조우(대화, 거래, 이동)
- 적 조우(전투, 도망)
- 집(아이템을 소모해 회복) 총 3턴
 */