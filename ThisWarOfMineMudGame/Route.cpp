#include "Route.h"
#include "Player.h"

using namespace std;

Route::Route(int routeCount)
    :  routCount(routeCount)
{
    
}

void Route::RandomEvent(int routeCount,Player& player)
{
    int random = 0;
    
    if (routeCount != 1)
    {
        cout << "################################################################\n";
        cout << "#                       탐색을 시작합니다.                       #\n";
        cout << "################################################################\n";
        for (int i = 0; i < routeCount; i++)
        {
            random = rand() % 10;
            if (routeCount > 5)
            {
                    if (random > 3 && random < 9){player.Loot();}
                    else
                    {
                        cout << "이봐, " << player.GetName()<<" 나랑 거래할텐가?"<<endl;
                        player.Trade();
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