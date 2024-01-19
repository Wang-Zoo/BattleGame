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
	std::cout << name <<"�����˼�Ѫ���� ";
	int random = CRandom::getInstance().getRandomIntRange(1, 10);
	float targetData = (float)mAttribute.ap;
	targetData += (targetData * random / 10);
	ally->healing((int)targetData);
	std::cout << "������"<<ally->GetName()<<"����" << targetData << "��Ѫ��\n";
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED| FOREGROUND_GREEN| FOREGROUND_BLUE|FOREGROUND_INTENSITY);

}

void CSupporter::RSkill(CHero* ally)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	std::cout << name << "�����˻��ܹ��� ";
	int random = CRandom::getInstance().getRandomIntRange(1, 10);
	float targetData = (float)mAttribute.ap;
	targetData += (targetData * random / 10);
	ally->SetDef((int)targetData);
	std::cout << "������" << ally->GetName() << "����" << targetData << "�㻤�ܣ�Ϊ�´η����ṩ�˱���\n";
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
