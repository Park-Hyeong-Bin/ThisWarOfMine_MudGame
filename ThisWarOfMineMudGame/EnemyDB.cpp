#include "EnemyDB.h"

unordered_map<string, EnemyDB> createEnemyDB(){
    
    unordered_map<string, EnemyDB> db;
    
    //평균 약탈자(범죄자)능력치
    db["Homeless"] = {35,10,10,0, {101,102,403}};
    db["Robbery"] = {60,10,15,2, {202,301,404}};
    
    //평균 군인
    db["Soldier"] = {75,10,10,5, {207,303,304,404}};
    
    //네임드 능력치
    db["DrunknSoldier"] = {75,10,10,3, {206,303,404}};
    db["Robbery"] = {60,10,15,3, {208,303,404}};
    
    return db;
}