#include "warrior.h"
#include "output.h"
#include <iostream>
#include "tool.h"

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
	enemy->GetAttribute()->hp -= gj;
	std::cout << "��" << enemy->GetName() << "������" << gj << "���˺�\n";

}

void CWarrior::RSkill(CHero* enemy)
{
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
	enemy->GetAttribute()->hp -= gj;
	std::cout << "��" << enemy->GetName() << "������" << gj << "���˺�\n";

}

void CWarrior::NormalAttack(CHero* enemy)
{
	int gj = mAttribute.ad;
	int tempRandom = getRandomInt();
	std::cout << name << "��������ͨ����";
	std::cout << "��" << enemy->GetName() << "������" << gj << "���˺�\n";

}

void CWarrior::setQcd(int cd)
{
	qcd = cd;
}

void CWarrior::setRcd(int cd)
{
	rcd = cd;
}
