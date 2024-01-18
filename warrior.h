#pragma once
#include"hero.h"
//Õ½Ê¿Ó¢ÐÛ
class CWarrior : public CHero, public CSkill {
public:
	void Run();
	void Action(CHero* tag);
	void QSkill(CHero* enemy);
	void RSkill(CHero* enemy);
	void NormalAttack(CHero* enemy);
};
