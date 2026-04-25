#include <algorithm>
#include <iostream>
#include <string>
#include "Character.h"
#include <vector>
#include "Player.h"
#include "Route.h"
using namespace std;

void nextPhase() {
    system("pause");
    system("cls");
}

int main(){
    
    string userName;
    int aliveTime = 0;
    system("cls");
    //1페이지 게임 타이틀 및 이름 생성
    cout << "################################################################\n";
    cout << "#                       This War Of Mine                       #\n";
    cout << "################################################################\n\n";
    
    nextPhase();
    
    cout << "당신의 이름을 적어주세요\n";
    cin >> userName;
    cout << "당신은 갑작스러운 전쟁속에 던져졌습니다.\n" << "자원들을 이용하여 이 전쟁 속 에서 살아 남으십시오.\n";
    
    //플레이어 객체 생성
    Player player(userName);
    nextPhase();
    
    //2페이지 집에서 행동
    while (player.isAlive() == true && aliveTime < 7)
    {
        player.HouseWork();
    
        nextPhase();
        //탐색 선택
        cout << "################################################################\n";
        cout << "#                       루트를 선택하세요                      #\n";
        cout << "################################################################\n\n";
        cout << "1. 안전한 루트 (안전, 거래 가능 npc존재, 탐색횟수 적음)\n";
        cout << "2. 병원 루트   (거래만 가능 npc만 있음, 탐색불가능)\n";
        cout << "3. 위험한 루트 (위험, 전투발생 가능, 탐색횟수 많음)\n";
        cout << "################################################################\n";
        int routInput = 0;
        int routeNum = 0;
        cin >> routInput;
        nextPhase();
        if (routInput != 1 && routInput != 2 && routInput != 3)
        {
            cout << "존재하지않는 입력 값 입니다. 안전 루트로 진행합니다.";
            routInput = 1;
        }
        switch (routInput)
        {
        case 1:
            {
                routeNum = 3;
                cout << "안전 루트로 진행합니다.\n";
                break;
            }
        case 2: {
                routeNum = 1;
                cout << "병원으로 출발합니다.\n";
                break;
        }
        case 3: {
                routeNum = 10;
                cout << "위험한 루트로 진행합니다.\n";
                break;
        }
        }
        Route Route(routeNum);
        //적 생성
        vector<Enemy> enemys={
            Enemy("술취한 군인", 80, 10, 25, 5, 6),
            Enemy("탈영 군인", 95, 10, 35, 8, 8),
            Enemy("빼빼 마른 노숙자", 15, 5, 4, 0, 0),
            Enemy("덩치 큰 노숙자", 40, 10, 12, 0, 1),
            Enemy("노숙자", 38, 10, 10, 0, 1),
            Enemy("상처많은 노숙자", 10, 10, 4, 0, 0),
            Enemy("약해 보이는 노숙자", 15, 10, 8, 0, 0),
            Enemy("덩치 큰 무장 강도", 70, 10, 18, 3, 4),
            Enemy("무장 강도", 60, 10, 15, 2, 3),
            Enemy("무장이 약한 강도", 55, 10, 18, 2, 2)
        };
        
        Route.RandomEvent(routeNum,player,enemys[rand() % enemys.size()]);
        if (player.isAlive() == true) {player.NewDay();}
    }
    //종료
    if (player.isAlive() != true)
    {
        cout << "  _______      ___      .___  ___.  _______ \n";
        cout << " /  _____|    /   \\     |   \\/   | |   ____|\n";
        cout << "|  |  __     /  ^  \\    |  \\  /  | |  |__   \n";
        cout << "|  | |_ |   /  /_\\  \\   |  |\\/|  | |   __|  \n";
        cout << "|  |__| |  /  _____  \\  |  |  |  | |  |____ \n";
        cout << " \\______| /__/     \\__\\ |__|  |__| |_______|\n";
        cout << "\n";
        cout << "  ______   ____    ____  _______ .______  \n";
        cout << " /  __  \\  \\   \\  /   / |   ____||   _  \\ \n";
        cout << "|  |  |  |  \\   \\/   /  |  |__   |  |_)  |\n";
        cout << "|  |  |  |   \\      /   |   __|  |      / \n";
        cout << "|  `--'  |    \\    /    |  |____ |  |\\  \\--.\n";
        cout << " \\______/      \\__/     |_______|| _| `.___|\n";
        if (player.GetHp() <= 0)
        {
            cout << "당신은 살아남지 못하였습니다.\n";
        }
        else if (player.GetSanity() <= 0){
            cout << "당신은 우울증에 시달려 자살하고 말았습니다.\n";
        }
    }
    else
    {
        cout<<"세상에 종전이 찾아왔습니다.\n";
        cout<<"당신은 이 전쟁 속 에서 살아 남았습니다.";
    }
    
}