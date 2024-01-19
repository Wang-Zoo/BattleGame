#pragma once
#include"hero.h"
//Õ½Ê¿Ó¢ÐÛ
class CWarrior : public CHero {
private:
	CWarrior();
	friend class CWarriorBuilder;
public:
	void Run();
	void Action(CHero* tag);
};
