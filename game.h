#pragma once
#include<vector>
#include"hero.h"
#include"team.h"
class CGAME :public CGetEnemyInter {
private:
	std::vector<CTEAM*> teams;
	void createLeftTeam();
	void createRightTeam();
	void createMiddleTeam();
	void createFourthTeam();
	void createFifthTeam();
	int getRandomTeamNum(int self);
public:
	void Init();
	void Run();
	void End();
	CHero *getEnemy(int selfTeamNum);
	CTEAM* getTeam(int selfTeamNum);
	void clearTraitor(CHero* traitor);
	CHero* findEnemyWarrior(int teamNum);
};