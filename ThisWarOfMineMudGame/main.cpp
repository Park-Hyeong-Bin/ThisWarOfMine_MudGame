#include <iostream>

using namespace std;

void nextPhase() {
    cout << "\n[Press Enter to Continue...]";
    cin.ignore(100, '\n');
    cin.get();
    system("cls"); // Windows 전용 화면 지우기
}


int main(){
    string userName;
    
    //1페이지 게임 타이틀 및 이름 생성
    cout << "################################################################\n";
    cout << "#전쟁 중에는 모두 평등하지 않다. 어떤 이들은 살아남고, 어떤 이들은 죽는다.#\n";
    cout << "#                       This War Of Mine                       #\n\n";
    cout << "################################################################\n\n";
    
    system("pause");
    system("cls");
    
    cout << "당신의 이름을 적어주세요" << endl;
    cin >> userName;
    cout << "이 전쟁 속 에서 살아 남으십시오.\n";
    
    Player player(userName);
    nextPhase();
    
    
        
        
    
}