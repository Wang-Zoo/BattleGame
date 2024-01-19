#pragma once
#include<vector>
#include"hero.h"



class CGAME {
private:
	std::vector<CHero*> leftTeam;
	std::vector<CHero*> rightTeam;	
	void createLeftTeam();
	void createRightTeam();
	void choose(bool isLeft);
public:
	void Init();
	void Run();
	void End();
};