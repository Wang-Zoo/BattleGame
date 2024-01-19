#include "supporter.h"
#include <iostream>
#include "random.h"
#include "windows.h"
CSupporter::CSupporter()
{
}
void CSupporter::Run()
{
	CHero::Run();
	CSkill::changeCD();
}

void CSupporter::Action(CHero* enemy)
{
	if (enemy == 0) {
		return;
	}
	if (!cqcd) {
		QSkill(enemy);
		cqcd = qcd;
	}
	else if (!crcd) {
		RSkill(enemy);
		crcd = rcd;
	}
	else {
		NormalAttack(enemy);
	}
}

void CSupporter::QSkill(CHero* ally)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	std::cout << name <<"开启了加血功能 ";
	int random = CRandom::getInstance().getRandomIntRange(1, 10);
	float targetData = (float)mAttribute.ap;
	targetData += (targetData * random / 10);
	ally->healing((int)targetData);
	std::cout << "给队友"<<ally->GetName()<<"加了" << targetData << "点血量\n";
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED| FOREGROUND_GREEN| FOREGROUND_BLUE|FOREGROUND_INTENSITY);

}

void CSupporter::RSkill(CHero* ally)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	std::cout << name << "开启了护盾功能 ";
	int random = CRandom::getInstance().getRandomIntRange(1, 10);
	float targetData = (float)mAttribute.ap;
	targetData += (targetData * random / 10);
	ally->SetDef((int)targetData);
	std::cout << "给队友" << ally->GetName() << "加了" << targetData << "点护盾，为下次防御提供了保障\n";
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}

void CSupporter::NormalAttack(CHero* enemy)
{
}

void CSupporter::setQcd(int cd)
{
	qcd = cd;
}

void CSupporter::setRcd(int cd)
{
	rcd = cd;
}
