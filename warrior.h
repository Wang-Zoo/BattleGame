#pragma once
#include"hero.h"
//սʿӢ��
class CWarrior : public CHero, public CSkill {
public:
	CWarrior();
	void Run();
	void Action(CHero* tag);
	void QSkill(CHero* enemy);
	void RSkill(CHero* enemy);
	void NormalAttack(CHero* enemy);
	void setQcd(int cd);
	void setRcd(int cd);
};
