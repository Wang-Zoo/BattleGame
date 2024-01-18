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

CWarriorBuilder& CWarriorBuilder::setQcd(int cd)
{
	target->setQcd(cd);
	return *this;
}

CWarriorBuilder& CWarriorBuilder::setRcd(int cd)
{
	target->setRcd(cd);
	return *this;
}

CWarriorBuilder& CWarriorBuilder::setHp(int hp)
{
	target->SetHp(hp);
	return *this;
}

CWarriorBuilder& CWarriorBuilder::setDef(int def)
{
	target->SetDef(def);
	return *this;
}

CHero* CWarriorBuilder::build()
{
	return target;
}
