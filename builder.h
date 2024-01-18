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
	CHero* build();
};

class CSupporterBuilder
{
private:
	CSupporter* target = new CSupporter;

public:
	CSupporterBuilder& setName(const char* name);
	CSupporterBuilder& setAP(int ad);
	CSupporterBuilder& setQcd(int cd);
	CSupporterBuilder& setRcd(int cd);
	CSupporterBuilder& setHp(int hp);
	CHero* build();
};
