#pragma once
#include<vector>
#include"hero.h"
class CGAME {
private:
	std::vector<CHero*> leftTeam;
	std::vector<CHero*> rightTeam;
public:
	void Init();
	void Run();
	void End();
};