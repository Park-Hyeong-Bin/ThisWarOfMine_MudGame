#include "Route.h"
#include "Player.h"
#include "Enemy.h"
#include "Map.h"
#include <string>
#include <iostream>
#include <vector>
#include <conio.h>

using namespace std;

Route::Route(int routeCount)
    :  routCount(routeCount)
{
    
}

void Route::ExploreMap(Player& player, Enemy& enemy, int routeType) {
    int mapSize = (routeType == 2) ? 6 : 20;
    Map gameMap(mapSize); 
    gameMap.Initialize(routeType);
    string msg = (routeType == 2) ? "당신은 병원에 도착하였습니다." : "미지의 구역에 도착하였습니다. 언제나 조심하세요!";
    bool exploring = true;

    while (exploring && player.isAlive()) {
        if (gameMap.IsTurnOver()) {
            msg = "시간이 되었습니다! 집으로 돌아갑니다...";
            gameMap.Render(player, msg);
            system("pause");
            break;
        }

        gameMap.Render(player, msg);
        char input = _getch();
        int eventType = 0;

        if (input == 'q' || input == 'Q') break;

        if (gameMap.MovePlayer(input, eventType)) {
            msg = (routeType == 2) ? "Walking through the corridor..." : "Walking through the ruins...";
            switch (eventType) {
            case 1: 
                msg = "물건이 모여있는 장소를 찾았습니다!" ;
                gameMap.Render(player, msg);
                player.Loot();
                system("pause");
                break;
            case 2: 
                msg = "조심하세요! 적과 조우하였습니다.!";
                gameMap.Render(player, msg);
                system("pause");
                if (!Battle(player, enemy)) {
                    msg = "적은 5턴 뒤에 당신을 쫓아옵니다..";
                    gameMap.AddChaser(gameMap.GetPlayerX(), gameMap.GetPlayerY());
                    gameMap.SetChaserWait(5);
                } else if (enemy.isAlive() == false) {
                    msg = "적을 처치하였습니다! 적의 시체를 뒤져봅니다.";
                    player.Loot(enemy.GetRewrad());
                }
                enemy.SetHp(); 
                break;
            case 3: 
                if (routeType == 2) {
                    msg = "의사가 당신을 바라봅니다. 의사는 당신에게서 물품을 기부받기를 원하는 것 같습니다.";
                    gameMap.Render(player, msg);
                    player.Hospital(); // 병원 전용 거래 호출
                } else {
                    msg = "그림자 뒤에 나타난건... 저와 거래하고싶은 남자입니다.";
                    gameMap.Render(player, msg);
                    player.Trade();
                }
                break;
            }
            
            // 탈출구 체크: 왼쪽 위(1,1) 또는 오른쪽 아래 끝
            int exitCoord = gameMap.GetSize() - 2;
            bool isAtStartExit = (gameMap.GetPlayerX() == 1 && gameMap.GetPlayerY() == 1);
            bool isAtEndExit = (gameMap.GetPlayerX() == exitCoord && gameMap.GetPlayerY() == exitCoord);

            // (1,1)은 최소 1턴 이상 소모했을 때만 작동하도록 함 (시작하자마자 나가는 것 방지)
            if (isAtEndExit || (isAtStartExit && gameMap.GetRemainingTurns() < (routeType == 2 ? 15 : (routeType == 1 ? 80 : 150)))) {
                msg = "Leaving the area...";
                gameMap.Render(player, msg);
                system("pause");
                exploring = false;
            }
            }
            }
            }

bool Route::Battle(Player& player,Enemy& enemy)
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
                        enemy.TakeDamage(dmg);
                        if (e_successRate <= 7 && enemy.isAlive())
                        {
                            dmg = enemy.GetDamage();
                            cout << ">>" << enemy.GetName() <<"이(가) 반격합니다!\n";
                            player.TakeDamage(dmg);
                        }
                    }
                    else {
                        cout << ">> 공격에 실패하였습니다!\n";
                        if (e_successRate <= 7)
                        {
                            dmg = enemy.GetDamage();
                            cout << ">>" << enemy.GetName() <<"이(가) 반격합니다!\n";
                            player.TakeDamage(dmg);
                        }
                    }
                    system("pause");
                    system("cls");
                    break;
                }
            case 2:
                {
                    if (successRate <= 3)
                    {
                        cout << ">> 당신은 도망치는 것에 성공하였습니다!\n";
                        system("pause");
                        system("cls");
                        return false; // 도망침
                    }
                    else
                    {
                        cout << ">> 도망치는 것에 실패하였습니다!\n";
                        if (e_successRate <= 7)
                        {
                            dmg = enemy.GetDamage();
                            cout << ">>" << enemy.GetName() <<"이(가) 반격합니다!\n";
                            player.TakeDamage(dmg);
                        }
                        system("pause");
                        system("cls");
                    }
                    break;
                }
        }
    }
    return true; // 전투 종료 (적 처치 혹은 사망)
}

void Route::RandomEvent(int routeCount,Player& player, Enemy& enemy)
{
    int random = 0;
    
    if (player.isAlive() == true)
    {
        if (routeCount != 1)
        {
            cout << "################################################################\n";
            cout << "#                       탐색을 시작합니다.                     #\n";
            cout << "################################################################\n";
            if (routeCount > 5)
            {
                cout << "         이번에 탐색에 등장하는 적은 "<< enemy.GetName() <<"입니다.\n";
                cout << "################################################################\n";
            }
            for (int i = 0; i < routeCount; i++)
            {
                cout<<"             남은 탐색 횟수 : " << routCount - i <<"\n";
                cout << "################################################################\n";
                random = rand() % 10;
                if (routeCount > 5)
                {
                    if (random < 5){player.Loot();}
                    else if (random < 7)
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
                    enemy.SetHp();
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
            cout << "물자를 지원해주시면 감사하겠습니다."<<endl;
            player.Hospital();
        }
    }
}