#pragma once
#include<vector>
#include"hero.h"

class CTEAM {
	int teamColor = 0;
	const char* teamName = 0;
	std::vector<CHero*> heros;
	bool onlySupporter();
	int getAliveNum();
	CHero* findWarroier();
	void randomDestory(CHero* supporter,CTEAM *enemyTeam);

public:
	CTEAM(int teamColor,const char* name);
	~CTEAM();
	void addHero(CHero* hero);
	CHero* findAlive();
	void battle(CTEAM * enemyTeam);
	void allDead(const char * enemyName);
	bool isAllDead();
	void displayTeamInfo();
	const char* getName();
};