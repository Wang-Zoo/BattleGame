#pragma once
#include"hero.h"
//սʿӢ��
class CWarrior : public CHero {
private:
	CWarrior();
	friend class CWarriorBuilder;
public:
	void Run();
	void Action(CHero* tag);
};
