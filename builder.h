#pragma once
#include"hero.h"
#include"warrior.h"
#include"supporter.h"
class CWarriorBuilder
{
private:
	CWarrior* target = new CWarrior;

public:
	CWarriorBuilder& setName(const char* name);
	CWarriorBuilder& setAD(int ad);
	CWarriorBuilder& setBJ(int bj);
	CWarriorBuilder& setQcd(int cd);
	CWarriorBuilder& setRcd(int cd);
	CWarriorBuilder& setHp(int hp);
	CWarriorBuilder& setDef(int def);
	CHero* build();
};
