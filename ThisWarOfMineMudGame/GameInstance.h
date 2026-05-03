#pragma once
#include <unordered_map>
#include "EnemyDB.h"
#include "ItemData.h"

using namespace std;

class GameInstance
{
private:
    GameInstance()
    {
        itemDB = createItemDB();
        enemyDB = createEnemyDB();
    }
    ~GameInstance() {}
    
    //복사/이동 금지 - 2번째 이상 객체 생성을 원천 차단
    GameInstance(const GameInstance&) = delete;
    GameInstance& operator=(const GameInstance&) = delete;
    
public:
    static GameInstance& GetGameInstance()
    {
        static GameInstance instance;
        return instance;
    }
    
    unordered_map<int, ItemData> itemDB;
    unordered_map<string, EnemyDB> enemyDB;
};
