#include "hero.h"

CHero::CHero()
{

}

void CHero::Run()
{

}

void CHero::Action(CHero* tag)
{

}

const char* CHero::GetName()
{
	return name;
}

void CHero::SetAD(int ad)
{
	this->mAttribute.ad = ad;
}

void CHero::SetAP(int ap)
{
	this->mAttribute.ap = ap;
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

int CHero::subDef(int gj)
{
	if(mAttribute.def==0){
		return gj;
	}
	else if(mAttribute.def >= gj) {
		SetDef(0);
		return 0;
	}
	else {
		return  gj - mAttribute.def;
	}
}

int CHero::getDef()
{
	return mAttribute.def;
}

void CHero::SetName(const char* name)
{
	this->name = name;
}

void CHero::damage(int hp)
{
	mAttribute.hp -= hp;
	if (mAttribute.hp <= 0) {
		dead();
	}
}

void CHero::healing(int hp)
{
	mAttribute.hp += hp;
}

void CHero::dead()
{
	alive = false;
}

bool CHero::isAlive()
{
	return alive;
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
