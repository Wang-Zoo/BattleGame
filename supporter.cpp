#include "supporter.h"
#include <iostream>
#include "random.h"

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
	std::cout << name <<"开启了加血功能 ";
	int random = CRandom::getInstance().getRandomIntRange(1, 10);
	float targetData = (float)mAttribute.ap;
	targetData += (targetData * random / 10);
	ally->GetAttribute()->hp += (int)targetData;
	std::cout << "给队友"<<ally->GetName()<<"加了" << targetData << "点血量\n";
}

void CSupporter::RSkill(CHero* enemy)
{
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
