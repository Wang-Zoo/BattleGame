#pragma once
#include"hero.h"
//սʿӢ��
class CSupporter : public CHero, public CSkill {
public:
	void Init();
	void Run();
	void Action(CHero* tag);
	const char* GetName();
	void QSkill(SAttribute* attribute);
	void RSkill(SAttribute* attribute);
	void NormalAttack(SAttribute* attribute);
};