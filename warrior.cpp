#include "warrior.h"
#include "output.h"
#include <iostream>
#include "tool.h"
#include "windows.h"

CWarrior::CWarrior()
{
	mAttribute.bjValue = 50;
}

void CWarrior::Run() {
	CHero::Run();
	CSkill::changeCD();
}

void CWarrior::Action(CHero* enemy)
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

void CWarrior::QSkill(CHero* enemy)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED| FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	int gj = mAttribute.ad;
	std::cout << name << "��������";
	int tempRandom = getRandomInt();
	if (tempRandom % 100 < mAttribute.bj) {//����
		gj +=( gj * this->mAttribute.bjValue/100);
		std::cout << "��������";
	}
	else {
		std::cout << "���У�";
	}
	int tempGj = enemy->subDef(gj);
	if (tempGj == gj) {
		enemy->damage(gj);
		std::cout << "��" << enemy->GetName() << "������" << gj << "���˺�\n";
	}
	else {
		std::cout << "��" << enemy->GetName() << "������" << gj << "���˺���";
		if (tempGj == 0) {
			std::cout << "������" << enemy->GetName() << "�л��ܣ����˴˴ι���\n";
		}
		else {
			std::cout << "������" << enemy->GetName() << "�л��ܣ�������" << gj - tempGj << "���˺�\n";
		}
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}

void CWarrior::RSkill(CHero* enemy)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	int gj = mAttribute.ad;
	std::cout << name << "�����˴��м���";
	int tempRandom = getRandomInt();
	if (tempRandom % 100 < mAttribute.bj) {//����
		gj += (gj * this->mAttribute.bjValue/100);
		std::cout << " ��������";
	}
	else {
		std::cout << " ����!";
	}
	int tempGj = enemy->subDef(gj);
	if (tempGj == gj) {
		enemy->damage(gj);
		std::cout << "��" << enemy->GetName() << "������" << gj << "���˺�\n";
	}
	else {
		std::cout << "��" << enemy->GetName() << "������" << gj << "���˺���";
		if (tempGj == 0) {
			std::cout << "������" << enemy->GetName() << "�л��ܣ����˴˴ι���\n";
		}else{
			std::cout << "������" << enemy->GetName() << "�л��ܣ�������" << gj-tempGj << "���˺�\n";
		}
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}

void CWarrior::NormalAttack(CHero* enemy)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	int gj = mAttribute.ad;
	int tempRandom = getRandomInt();
	std::cout << name << "��������ͨ����";
	int tempGj = enemy->subDef(gj);
	if (tempGj == gj) {
		enemy->damage(gj);
		std::cout << "��" << enemy->GetName() << "������" << gj << "���˺�\n";
	}
	else {
		std::cout << "��" << enemy->GetName() << "������" << gj << "���˺���";
		if (tempGj == 0) {
			std::cout << "������" << enemy->GetName() << "�л��ܣ����˴˴ι���\n";
		}
		else {
			std::cout << "������" << enemy->GetName() << "�л��ܣ�������" << gj - tempGj << "���˺�\n";
		}
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}

void CWarrior::setQcd(int cd)
{
	qcd = cd;
}

void CWarrior::setRcd(int cd)
{
	rcd = cd;
}
