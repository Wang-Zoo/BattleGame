#pragma once
#include"hero.h"
//սʿӢ��
class CDefender : public CHero {
public:
	void Init();
	void Run();
	void Action(CHero* tag);
	const char* GetName();
	void QSkill(SAttribute* attribute);
	void RSkill(SAttribute* attribute);
	void NormalAttack(SAttribute* attribute);
};