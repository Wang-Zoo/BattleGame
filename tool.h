#pragma once
#include"hero.h"
#include<vector>

typedef bool (*HeroCallback)(CHero*);
typedef void (*HeroCallbackAll)(CHero*, std::vector<CHero*>* ourTeam, std::vector<CHero*>* enemyTeam);

CHero* forEach(std::vector<CHero*>* origins, HeroCallback callback);
void forEach(std::vector<CHero*>* origins, std::vector<CHero*>* leftTeam,std::vector<CHero*>* rightTeam, HeroCallbackAll callback);

void randomInit();
int getRandomInt();
int getRandomIntRange(int max, int min);
bool getPercent(int target);


