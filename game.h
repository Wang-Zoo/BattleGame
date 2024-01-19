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
	void displayHero(bool isLeft);
	bool isAllDead(bool isLeft);
public:
	void Init();
	void Run();
	void End();
};