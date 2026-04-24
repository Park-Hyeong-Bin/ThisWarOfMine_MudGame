#include <iostream>
#include <string>
#include "Character.h"
#include "Player.h"


using namespace std;

void nextPhase() {
    system("pause");
    system("cls");
}


int main(){
    string userName;
    system("cls");
    //1페이지 게임 타이틀 및 이름 생성
    cout << "################################################################\n";
    cout << "#                       This War Of Mine                       #\n";
    cout << "################################################################\n\n";
    
    nextPhase();
    
    cout << "당신의 이름을 적어주세요" << endl;
    cin >> userName;
    cout << "당신은 갑작스러운 전쟁속에 던져졌습니다.\n" << "자원들을 이용하여 이 전쟁 속 에서 살아 남으십시오.\n";
    
    Player player(userName);
    nextPhase();
    
    //2페이지 집에서 행동
    player.HouseWork();
    
    //탐색 선택
    
    
    
    
    
        
        
    
}