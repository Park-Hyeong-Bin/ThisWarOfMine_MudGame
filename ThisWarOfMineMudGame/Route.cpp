#include "Route.h"
#include "Player.h"
#include "Enemy.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

Route::Route(int routeCount)
    :  routCount(routeCount)
{
    
}

void Route::Battle(Player& player,Enemy& enemy)
{
    int action;
    int successRate = 0;
    int e_successRate = 0;
    bool fight = true;
    int dmg = 0;
    
    while (enemy.isAlive() && player.isAlive() && fight == true)
    {
        cout << "\n[" << enemy.GetName() << " : " << enemy.GetHp() << " HP ] vs [ " << player.GetName() << ": " << player.GetHp() << " HP ]\n";
        cout << "1. 공격하기!(성공률 80%)  | 2. 도망가기!(성공률 30%) \nAction: ";
        cin >> action;
        successRate = rand() % 10;
        e_successRate = rand() % 10;
        
        switch (action)
        {
            case 1:
                {
                    if (successRate <= 7)
                    {
                        dmg = player.GetDamage();
                        cout << ">> 공격에 성공해였습니다!\n";
                        cout << ">> 당신은 ";
                        enemy.TakeDamage(dmg);
                        cout << "피해를 주었습니다!\n";
                        if (e_successRate <= 7)
                        {
                            dmg = enemy.GetDamage();
                            cout << ">>" << enemy.GetName() <<"이(가) 반격합니다!\n";
                            cout << ">> 당신은 ";
                            player.TakeDamage(dmg);
                            cout << "피해를 받았습니다!\n";
                        }
                        else {
                            cout << ">> 적이 공격에 실패하였습니다!\n";
                        }
                        system("pause");
                        system("cls");
                    }
                    else {
                        cout << ">> 공격에 실패하였습니다!\n";
                        if (e_successRate <= 7)
                        {
                            dmg = enemy.GetDamage();
                            cout << ">>" << enemy.GetName() <<"이(가) 반격합니다!\n";
                            cout << ">> 당신은 ";
                            player.TakeDamage(dmg);
                            cout << "피해를 받았습니다!\n";
                        }
                        else {
                            cout << ">> 적이 공격에 실패하였습니다!\n";
                        }
                        system("pause");
                        system("cls");
                    }
                    break;
                }
            case 2:
                {
                    if (successRate <= 3)
                    {
                        cout << ">>당신은 도망치는 것에 성공하였습니다!\n";
                        system("pause");
                        system("cls");
                        fight = false;
                    }
                    else
                    {
                        cout << ">> 당신은 도망치는 것에 실패하였습니다,\n";
                        if (e_successRate <= 7)
                        {
                            dmg = enemy.GetDamage();
                            cout << ">>" << enemy.GetName() <<"이(가) 반격합니다!\n";
                            cout << ">> 당신은 ";
                            player.TakeDamage(dmg);
                            cout << "피해를 받았습니다!\n";
                        }
                        else {
                            cout << ">> 적이 공격에 실패하였습니다!\n";
                        }
                        system("pause");
                        system("cls");
                    }
                    break;
                }
        }
    }
}

void Route::RandomEvent(int routeCount,Player& player, Enemy& enemy)
{
    int random = 0;
    
    if (player.isAlive() == true)
    {
        if (routeCount != 1)
        {
            cout << "################################################################\n";
            cout << "#                       탐색을 시작합니다.                       #\n";
            cout << "################################################################\n";
            for (int i = 0; i < routeCount; i++)
            {
                cout<<"             남은 탐색 횟수 : " << routCount - i <<"\n";
                cout << "################################################################\n";
                random = rand() % 10;
                if (routeCount > 5)
                {
                    if (random > 3 && random < 7){player.Loot();}
                    else if (random >7)
                    {
                        cout << "이봐, " << player.GetName()<<" 나랑 거래할텐가?"<<endl;
                        player.Trade();
                    }
                    else
                    {
                        cout << enemy.GetName()<<"을(를) 조우하였습니다."<<endl;
                        cout << enemy.GetName()<<"은(는) 이번 탐색 동안 계속 쫓아옵니다."<<endl;
                        cout << enemy.GetName()<<"와(과)의 전투페이즈에 돌입합니다."<<endl;
                        Battle(player,enemy);
                        if (player.isAlive() == false)
                        {
                            cout << "당신은 전투에서 패배하였습니다...\n";
                            system("pause");
                            break;
                        }
                        else if (enemy.isAlive() == false)
                        {
                            cout << "당신은 전투에서 승리하였습니다!\n";
                            player.Loot(enemy.GetRewrad());
                        }
                    }
                }
                else
                {
                    if (random > 3)
                    {
                        player.Loot();
                    }
                    else
                    {
                        cout << "자네가 물건을 주면 도움을 주도록하지, " << player.GetName()<<endl;
                        player.Trade();
                    }
                }
            }
        }
        else
        {
            cout << "안녕하세요, " << player.GetName()<<endl;
            cout << "물자를 지원해주신다면 치료해드리도록 하겠습니다."<<endl;
            player.Trade();
        }
    }
}