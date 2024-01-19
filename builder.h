#pragma once
#include"hero.h"
#include"warrior.h"
#include"supporter.h"
class CBaseBuilder
{
protected:
	CHero* target  = 0;
public:
	CBaseBuilder& setName(const char* name);
	CBaseBuilder& setAD(int ad);
	CBaseBuilder& setBJ(int bj);
	CBaseBuilder& setHp(int hp);
	CBaseBuilder& setAP(int ad);
	CBaseBuilder& addSkill(CSkill *s);
	CHero* build();
};

class CWarriorBuilder:public CBaseBuilder
{
public:
	CWarriorBuilder();
};

class CSupporterBuilder :public CBaseBuilder
{
public :
	CSupporterBuilder();
};
