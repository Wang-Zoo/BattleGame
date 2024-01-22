#pragma once
#include<vector>
#include"hero.h"
#include"team.h"
class CGAME {
private:
	std::vector<CTEAM*> teams;
	void createLeftTeam();
	void createRightTeam();
	void createMiddleTeam();
	int getRandomTeamNum(int self);
public:
	void Init();
	void Run();
	void End();
};