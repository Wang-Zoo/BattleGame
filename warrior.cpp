#include "warrior.h"
#include "output.h"
#include <iostream>
#include "random.h"

void CWarrior::Run() {
	CHero::Run();
	CSkill::changeCD();
}

void CWarrior::Action(CHero* tag)
{
	if (!cqcd) {
		QSkill(tag);
		cqcd = qcd;
	}else if (!crcd) {
		RSkill(tag);
		crcd = rcd;
	}else {
		NormalAttack(tag);
	}
}

void CWarrior::QSkill(CHero* enemy)
{
	int gj = mAttribute.ad;
	std::cout << name << "发动了Q技能";
	int tempRandom = CRandom::getInstance().getRandomInt();
	if (tempRandom % 100 < mAttribute.bj) {//暴击
		gj = gj * this->mAttribute.bjValue;
		std::cout << " 暴击！！";
	}
	else {
		std::cout << " 击中！！";
	}
	std::cout << "对" << enemy->GetName() << "产生了" << gj << "点伤害";

}

void CWarrior::RSkill(CHero* enemy)
{
	int gj = mAttribute.ad;
	std::cout << name << "发动了R技能";
	int tempRandom = CRandom::getInstance().getRandomInt();
	if (tempRandom % 100 < mAttribute.bj) {//暴击
		gj = gj * this->mAttribute.bjValue;
		std::cout << " 暴击！！";
	}
	else {
		std::cout << " 击中！！";
	}
	std::cout << "对" << enemy->GetName() << "产生了" << gj << "点伤害";

}

void CWarrior::NormalAttack(CHero* enemy)
{
	int gj = mAttribute.ad;
	int tempRandom = CRandom::getInstance().getRandomInt();
	std::cout << name << "发动了普通攻击";
	std::cout << "对" << enemy->GetName() << "产生了" << gj << "点伤害";

}
