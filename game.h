#pragma once
#include<vector>
#include"hero.h"

typedef void (*HeroCallback)(CHero *);

class CGAME {
private:
	std::vector<CHero*> leftTeam;
	std::vector<CHero*> rightTeam;	
	void forEach(std::vector<CHero*> *origins,HeroCallback callback);

public:
	void Init();
	void Run();
	void End();
};