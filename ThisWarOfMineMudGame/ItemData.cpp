#include "ItemData.h"



unordered_map<int, ItemData> createItemDB()
{
     
    unordered_map<int, ItemData> db;
    
    //100번대  Material
    db[101] = {"잡동사니", ItemType::Material};
    db[102] = {"목재", ItemType::Material};
    db[103] = {"무기 부품", ItemType::Material};
    db[104] = {"전자 부품", ItemType::Material};
    db[105] = {"기계 부품", ItemType::Material};
    db[106] = {"부서진 권총", ItemType::Material};
    
    //200번대 Weapon
    db[201] = {"식칼", ItemType::Weapon};
    db[202] = {"조잡한 단검", ItemType::Weapon};
    db[203] = {"조잡한 도끼", ItemType::Weapon};
    db[204] = {"소방용 도끼", ItemType::Weapon};
    db[205] = {"조잡한 권총", ItemType::Weapon};
    db[206] = {"권총", ItemType::Weapon};
    db[207] = {"돌격 소총", ItemType::Weapon};
    db[208] = {"산탄총", ItemType::Weapon};
    
    //300번대 Armor
    db[301] = {"낡은 방탄복", ItemType::Armor};
    db[302] = {"낡은 방탄 헬멧", ItemType::Armor};
    db[303] = {"방탄복", ItemType::Armor};
    db[304] = {"방탄 헬멧", ItemType::Armor};
    
    
    //400번대 Comsumable
    db[401] = {"고기", ItemType::Consumable};
    db[402] = {"채소", ItemType::Consumable};
    db[403] = {"물", ItemType::Consumable};
    db[404] = {"통조림", ItemType::Consumable};
    db[405] = {"커피", ItemType::Consumable};
    db[406] = {"담배", ItemType::Consumable};
    db[407] = {"의학품", ItemType::Consumable};
    
    //500번대 ETC : 주로 거래용 아이템
    db[501] = {"귀금속", ItemType::ETC};
    db[502] = {"책", ItemType::ETC};
    db[503] = {"인형", ItemType::ETC};
    return db;
}