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
	std::cout << name << "发动技能";
	int tempRandom = getRandomInt();
	if (tempRandom % 100 < mAttribute.bj) {//暴击
		gj +=( gj * this->mAttribute.bjValue/100);
		std::cout << "暴击！！";
	}
	else {
		std::cout << "击中！";
	}
	int tempGj = enemy->subDef(gj);
	if (tempGj == gj) {
		enemy->damage(gj);
		std::cout << "对" << enemy->GetName() << "产生了" << gj << "点伤害\n";
	}
	else {
		std::cout << "对" << enemy->GetName() << "产生了" << gj << "点伤害，";
		if (tempGj == 0) {
			std::cout << "但由于" << enemy->GetName() << "有护盾，格挡了此次攻击\n";
		}
		else {
			std::cout << "但由于" << enemy->GetName() << "有护盾，抵消了" << gj - tempGj << "点伤害\n";
		}
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}

void CWarrior::RSkill(CHero* enemy)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	int gj = mAttribute.ad;
	std::cout << name << "发动了大招技能";
	int tempRandom = getRandomInt();
	if (tempRandom % 100 < mAttribute.bj) {//暴击
		gj += (gj * this->mAttribute.bjValue/100);
		std::cout << " 暴击！！";
	}
	else {
		std::cout << " 击中!";
	}
	int tempGj = enemy->subDef(gj);
	if (tempGj == gj) {
		enemy->damage(gj);
		std::cout << "对" << enemy->GetName() << "产生了" << gj << "点伤害\n";
	}
	else {
		std::cout << "对" << enemy->GetName() << "产生了" << gj << "点伤害，";
		if (tempGj == 0) {
			std::cout << "但由于" << enemy->GetName() << "有护盾，格挡了此次攻击\n";
		}else{
			std::cout << "但由于" << enemy->GetName() << "有护盾，抵消了" << gj-tempGj << "点伤害\n";
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
	std::cout << name << "发动了普通攻击";
	int tempGj = enemy->subDef(gj);
	if (tempGj == gj) {
		enemy->damage(gj);
		std::cout << "对" << enemy->GetName() << "产生了" << gj << "点伤害\n";
	}
	else {
		std::cout << "对" << enemy->GetName() << "产生了" << gj << "点伤害，";
		if (tempGj == 0) {
			std::cout << "但由于" << enemy->GetName() << "有护盾，格挡了此次攻击\n";
		}
		else {
			std::cout << "但由于" << enemy->GetName() << "有护盾，抵消了" << gj - tempGj << "点伤害\n";
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
