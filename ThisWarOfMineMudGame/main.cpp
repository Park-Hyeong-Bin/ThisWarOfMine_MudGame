#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>
#include <ctime>
#include <cstdlib>

#include "Character.h"
#include "ItemData.h"
#include "Player.h"
#include "Collector.h"
#include "FireFighter.h"
#include "Deserter.h"
#include "Route.h"
#include "GameInstance.h"

using namespace std;

void nextPhase() {
    system("pause");
    system("cls");
}

int main(){
    srand(static_cast<unsigned int>(time(NULL)));
    
    string userName;
    int aliveTime = 0;
    system("cls");
    
    cout << "################################################################\n";
    cout << "#                       This War Of Mine                       #\n";
    cout << "################################################################\n\n";
    
    nextPhase();
    
    cout << "당신의 이름을 적어주세요\n";
    cin >> userName;

    cout << "직업을 선택하세요 (1. 수집가, 2. 소방관, 3. 탈영병, 그 외. 일반인)\n";
    int classChoiceInput;
    if (!(cin >> classChoiceInput)) {
        cin.clear();
        cin.ignore(1000, '\n');
        classChoiceInput = 0;
    }

    string charactorClass = "일반인";
    shared_ptr<Player> playerPtr;
    
    if (classChoiceInput == 1) {
        playerPtr = make_shared<Collector>(userName);
        charactorClass = "수집가";
    }
    else if (classChoiceInput == 2) {
        playerPtr = make_shared<FireFighter>(userName);
        charactorClass = "소방관";
    }
    else if (classChoiceInput == 3) {
        playerPtr = make_shared<Deserter>(userName);
        charactorClass = "탈영병";
    }
    else {
        playerPtr = make_shared<Player>(userName, charactorClass);
    }

    if (!playerPtr) {
        cout << "플레이어 생성에 실패했습니다.\n";
        return 1;
    }

    Player& player = *playerPtr;

    cout << "\n[" << charactorClass << "] " << userName << "(으)로 게임을 시작합니다.\n";
    cout << "당신은 갑작스러운 전쟁속에 던져졌습니다.\n" << "자원들을 이용하여 이 전쟁 속 에서 살아 남으십시오.\n";
    
    nextPhase();
    
    GameInstance& gameInstance = GameInstance::GetGameInstance();
    auto& enemyDB = gameInstance.enemyDB;
    
    vector<Enemy> enemys;
    for(auto& pair : enemyDB) {
        enemys.emplace_back(pair.first, pair.second);
    }
    
    while (player.isAlive() == true && aliveTime < 7)
    {
        // 낮 시간 활동
        player.HouseWork();
        nextPhase();

        // 탐색 루트 선택
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
            cout << "존재하지않는 입력 값 입니다. 안전 루트로 진행합니다.\n";
            routInput = 1;
        }
        
        switch (routInput)
        {
        case 1:
            routeNum = 3;
            cout << "안전 루트로 진행합니다.\n";
            break;
        case 2:
            routeNum = 1;
            cout << "병원으로 출발합니다.\n";
            break;
        case 3:
            routeNum = 10;
            cout << "위험한 루트로 진행합니다.\n";
            break;
        }
        
        Route currentRoute(routeNum);
        
        if (!enemys.empty()) {
            currentRoute.RandomEvent(routeNum, player, enemys[rand() % enemys.size()]);
        } else {
            cout << "등장할 적이 없습니다.\n";
            system("pause");
        }
        
        if (player.isAlive() == true) {
            player.NewDay();
            aliveTime++;
        }
    }

    // 종료 페이즈
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
        cout << "세상에 종전이 찾아왔습니다.\n";
        cout << "당신은 이 전쟁 속 에서 살아 남았습니다.\n";
    }
    
    return 0;
}