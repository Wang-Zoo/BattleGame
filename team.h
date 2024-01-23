#pragma once
#include<vector>
#include"hero.h"

class CGetEnemyInter;
class CTEAM {
	int teamColor = 0;
	int teamNum = -1;
	const char* teamName = 0;
	std::vector<CHero*> heros;
	bool onlySupporter();
	int getAliveNum();
	CHero* findWarroier();
	void randomDestory(CHero* supporter,CTEAM *enemyTeam);

public:
	CTEAM(int teamColor,const char* name,int teamNum);
	~CTEAM();
	void addHero(CHero* hero);
	CHero* findAlive();
	void battle(CGetEnemyInter* inter);
	void allDead(const char * enemyName);
	bool isAllDead();
	void displayTeamInfo();
	const char* getName();
	bool onlySupproterAlive();
	CHero* findTargetWarroier();
	int getTeamNum();
};

class CGetEnemyInter {
public:
	virtual CHero* getEnemy(int selfTeamNum) = 0;
	virtual CTEAM* getTeam(int selfTeamNum) = 0;
	virtual void clearTraitor(CHero* traitor) = 0;
	virtual CHero* findEnemyWarrior(int teamNum) = 0;
};