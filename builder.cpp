#include "builder.h"

CBaseBuilder& CBaseBuilder::setName(const char* name)
{
	target->SetName(name);
	return *this;
}

CBaseBuilder& CBaseBuilder::setAD(int ad)
{
	target->SetAD(ad);
	return *this;
}

CBaseBuilder& CBaseBuilder::setBJ(int bj)
{
	target->SetBJ(bj);
	return *this;
}

CBaseBuilder& CBaseBuilder::setAP(int ap)
{
	target->SetAP(ap);
	return *this;
}

CBaseBuilder& CBaseBuilder::addSkill(CSkill *s)
{
	target->addSkill(s);
	return *this;
}


CBaseBuilder& CBaseBuilder::setHp(int hp)
{
	target->SetHp(hp);
	return *this;
}

CHero* CBaseBuilder::build(int num)
{
	target->setTeamNum(num);
	return target;
}

CSupporterBuilder::CSupporterBuilder()
{
	target = new CSupporter;
}

CWarriorBuilder::CWarriorBuilder()
{
	target = new CWarrior;
}
