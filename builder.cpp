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

CHero* CWarriorBuilder::build()
{
	return target;
}

CSupporterBuilder& CSupporterBuilder::setName(const char* name)
{
	target->SetName(name);
	return *this;
}

CSupporterBuilder& CSupporterBuilder::setAP(int ap)
{
	target->SetAP(ap);
	return *this;
}

CSupporterBuilder& CSupporterBuilder::setQcd(int cd)
{
	target->setQcd(cd);
	return *this;
}

CSupporterBuilder& CSupporterBuilder::setRcd(int cd)
{
	target->setRcd(cd);
	return *this;
}

CSupporterBuilder& CSupporterBuilder::setHp(int hp)
{
	target->SetHp(hp);
	return *this;
}

CHero* CSupporterBuilder::build()
{
	return target;
}
