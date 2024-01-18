#include "hero.h"

void CHero::Run()
{

}

void CHero::Action(CHero* tag)
{

}

SAttribute* CHero::GetAttribute()
{
	return &mAttribute;
}

const char* CHero::GetName()
{
	return name;
}

void CHero::SetAD(int ad)
{
	this->mAttribute.ad = ad;
}

void CHero::SetBJ(int bj)
{
	this->mAttribute.bj = bj;
}

void CHero::SetHp(int hp)
{
	this->mAttribute.hp = hp;
}

void CHero::SetDef(int def)
{
	this->mAttribute.def = def;
}

void CHero::SetName(const char* name)
{
	this->name = name;
}

int CHero::getHp()
{
	return mAttribute.hp;
}

int CHero::getState()
{
	return mState;
}

void CHero::setState(int state)
{
	mState = state;
}

void CSkill::changeCD()
{
	if (cqcd) {
		cqcd--;
		if (cqcd < 0) {
			cqcd = 0;
		}
	}
	if (crcd) {
		crcd--;
		if (crcd < 0) {
			crcd = 0;
		}
	}
}
