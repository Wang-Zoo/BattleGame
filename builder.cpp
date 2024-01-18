#include "builder.h"

CWarriorBuilder& CWarriorBuilder::setName(const char* name)
{
	target->SetName(name);
	return *this;
}

CWarriorBuilder& CWarriorBuilder::setAD(int ad)
{
	target->SetAD(ad);
	return *this;
}

CWarriorBuilder& CWarriorBuilder::setBJ(int bj)
{
	target->SetBJ(bj);
	return *this;
}

CHero* CWarriorBuilder::build()
{
	return target;
}
