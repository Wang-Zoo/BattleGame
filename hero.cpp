#include "hero.h"
#include "windows.h"
#include "tool.h"
#include "iostream"
CHero::CHero()
{

}

CHero::~CHero()
{
	auto it = skills.begin();
	for (; it != skills.end(); it++) {
		delete (*it);
		(*it) = nullptr;
	}
}

void CHero::Run()
{
	std::vector<CSkill*>::iterator it = skills.begin();
	for (; it != skills.end(); it++) {
		(*it)->changeCD();
	}
}

void CHero::Action(CHero* hero)
{
	if (hero == 0) {
		return;
	}
	std::vector<CSkill*>::iterator it = skills.begin();
	for (; it != skills.end(); it++) {
		if (!(*it)->getCCD()) {
			(*it)->resetCD();
			(*it)->Action(this, hero);
			break;
		}
	}
}

const char* CHero::GetName()
{
	return name;
}

void CHero::SetAD(int ad)
{
	this->mAttribute.ad = ad;
}

int CHero::getAD()
{
	return mAttribute.ad;
}

int CHero::getAP()
{
	return mAttribute.ap;
}

int CHero::getBJ()
{
	return mAttribute.bj;
}

int CHero::getBJValue()
{
	return mAttribute.bjValue;
}

void CHero::SetAP(int ap)
{
	this->mAttribute.ap = ap;
}

void CHero::SetBJ(int bj)
{
	this->mAttribute.bj = bj;
}

void CHero::SetHp(int hp)
{
	this->mAttribute.hp = hp;
}

void CHero::SetDef(int def)
{
	this->mAttribute.def = def;
}

int CHero::subDef(int gj)
{
	SetDef(0);
	if(mAttribute.def >= gj) {
		return 0;
	}
	else {
		return  gj - mAttribute.def;
	}
}

int CHero::getDef()
{
	return mAttribute.def;
}

std::vector<CSkill*>* CHero::getSkills()
{
	return &skills;
}

void CHero::addSkill(CSkill *s)
{
	skills.push_back(s);
}

void CHero::SetName(const char* name)
{
	this->name = name;
}

void CHero::damage(int hp)
{
	mAttribute.hp -= hp;
	if (mAttribute.hp <= 0) {
		dead();
	}
}

void CHero::healing(int hp)
{
	mAttribute.hp += hp;
}

void CHero::dead()
{
	alive = false;
}

bool CHero::isAlive()
{
	return alive;
}

int CHero::getHp()
{
	return mAttribute.hp;
}

int CHero::getState()
{
	return mState;
}

void CHero::setState(int state)
{
	mState = state;
}

CNormalAttack::CNormalAttack()
{
	cd = 0;
	ccd = 0;
}

void CNormalAttack::Action(CHero* ally, CHero* enemy)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	int gj = ally->getAD();
	std::cout << ally->GetName() << "ʹ����" <<getName();
	int tempGj = enemy->subDef(gj);
	calculate(tempGj, gj, enemy);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

}

const char* CNormalAttack::getName()
{
	return "����ͨ������";
}

void CSkill::calculate(int tempGj, int gj,CHero *enemy)
{
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
}

int CSkill::getCCD()
{
	return ccd;
}

void CSkill::resetCD()
{
	ccd = cd;
}

void CSkill::Action(CHero* ally, CHero* enemy)
{
}

const char* CSkill::getName()
{
	return nullptr;
}

void CSkill::changeCD()
{
	if (ccd) {
		ccd--;
		if (ccd < 0) {
			ccd = 0;
		}
	}
}

CWarriorSkillNumber1::CWarriorSkillNumber1()
{
	cd = 5;
	ccd = 0;
}

void CWarriorSkillNumber1::Action(CHero* ally, CHero* enemy)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	int gj = ally->getAD();
	std::cout << ally->GetName() <<"ʹ����" << getName();
	int tempRandom = getRandomInt();
	if (tempRandom % 100 < ally->getBJ()) {//����
		gj += (gj * ally->getBJValue() / 100);
		std::cout << "��������";
	}
	else {
		std::cout << "���У�";
	}
	int tempGj = enemy->subDef(gj);
	calculate(tempGj, gj, enemy);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}

const char* CWarriorSkillNumber1::getName()
{
	return "�����G����";
}

CHealingSkillNumberOne::CHealingSkillNumberOne()
{
	cd = 5;
}

void CHealingSkillNumberOne::Action(CHero* ally, CHero* other)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	std::cout << ally->GetName() << "�����˼�Ѫ���� "<<getName();
	int random = getRandomIntRange(1, 10);
	float targetData = (float)ally->getAP();
	targetData += (targetData * random / 10);
	other->healing((int)targetData);
	std::cout << "������" << other->GetName() << "����" << targetData << "��Ѫ��\n";
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}

const char* CHealingSkillNumberOne::getName()
{
	return "������ˮ��";
}

CHealingSkillNumberTwo::CHealingSkillNumberTwo()
{
	cd = 3;
}

void CHealingSkillNumberTwo::Action(CHero* ally, CHero* other)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	std::cout << ally->GetName() << "�����˻��ܹ��� "<< getName();
	int random = getRandomIntRange(1, 10);
	float targetData = (float)ally->getAP();
	targetData += (targetData * random / 10);
	other->SetDef((int)targetData);
	std::cout << "������" << other->GetName() << "����" << targetData << "�㻤�ܣ�Ϊ�´η����ṩ�˱���\n";
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}

const char* CHealingSkillNumberTwo::getName()
{
	return "�����Է�����";
}

CWarriorSkillNumber2::CWarriorSkillNumber2()
{
	cd = 5;
}

void CWarriorSkillNumber2::Action(CHero* ally, CHero* enemy)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	int gj = ally->getAD();
	std::cout << ally->GetName() << "ʹ����" << getName();
	int tempRandom = getRandomInt();
	if (tempRandom % 100 < ally->getBJ()) {//����
		gj += (gj * ally->getBJValue() / 100);
		std::cout << "��������";
	}
	else {
		std::cout << "���У�";
	}
	int tempGj = enemy->subDef(gj);
	calculate(tempGj, gj, enemy);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}

const char* CWarriorSkillNumber2::getName()
{
	return "����������ǹ��";
}

CWarriorSkillNumber3::CWarriorSkillNumber3()
{
	cd = 5;
}

void CWarriorSkillNumber3::Action(CHero* ally, CHero* enemy)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	int gj = ally->getAD();
	std::cout << ally->GetName() << "ʹ����" << getName();
	int tempRandom = getRandomInt();
	if (tempRandom % 100 < ally->getBJ()) {//����
		gj += (gj * ally->getBJValue() / 100);
		std::cout << "��������";
	}
	else {
		std::cout << "���У�";
	}
	int tempGj = enemy->subDef(gj);
	calculate(tempGj, gj, enemy);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}

const char* CWarriorSkillNumber3::getName()
{
	return "�����˷�֮ǹ��";
}

CWarriorSkillNumber8::CWarriorSkillNumber8()
{
	cd = 5;
}

void CWarriorSkillNumber8::Action(CHero* ally, CHero* enemy)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	int gj = ally->getAD();
	std::cout << ally->GetName() << "ʹ����" << getName();
	int tempRandom = getRandomInt();
	if (tempRandom % 100 < ally->getBJ()) {//����
		gj += (gj * ally->getBJValue() / 100);
		std::cout << "��������";
	}
	else {
		std::cout << "���У�";
	}
	int tempGj = enemy->subDef(gj);
	calculate(tempGj, gj, enemy);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}

const char* CWarriorSkillNumber8::getName()
{
	return "�������ݻ�ͣ������";
}

CWarriorSkillNumber7::CWarriorSkillNumber7()
{
	cd = 5;
}

void CWarriorSkillNumber7::Action(CHero* ally, CHero* enemy)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	int gj = ally->getAD();
	std::cout << ally->GetName() << "ʹ����" << getName();
	int tempRandom = getRandomInt();
	if (tempRandom % 100 < ally->getBJ()) {//����
		gj += (gj * ally->getBJValue() / 100);
		std::cout << "��������";
	}
	else {
		std::cout << "���У�";
	}
	int tempGj = enemy->subDef(gj);
	calculate(tempGj, gj, enemy);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}

const char* CWarriorSkillNumber7::getName()
{
	return "����ѻ���ɻ���";
}

CWarriorSkillNumber6::CWarriorSkillNumber6()
{
	cd = 5;
}

void CWarriorSkillNumber6::Action(CHero* ally, CHero* enemy)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	int gj = ally->getAD();
	std::cout << ally->GetName() << "ʹ����" << getName();
	int tempRandom = getRandomInt();
	if (tempRandom % 100 < ally->getBJ()) {//����
		gj += (gj * ally->getBJValue() / 100);
		std::cout << "��������";
	}
	else {
		std::cout << "���У�";
	}
	int tempGj = enemy->subDef(gj);
	calculate(tempGj, gj, enemy);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}

const char* CWarriorSkillNumber6::getName()
{
	return "���������µ���";
}

CWarriorSkillNumber5::CWarriorSkillNumber5()
{
	cd = 5;
}

void CWarriorSkillNumber5::Action(CHero* ally, CHero* enemy)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	int gj = ally->getAD();
	std::cout << ally->GetName() << "ʹ����" << getName();
	int tempRandom = getRandomInt();
	if (tempRandom % 100 < ally->getBJ()) {//����
		gj += (gj * ally->getBJValue() / 100);
		std::cout << "��������";
	}
	else {
		std::cout << "���У�";
	}
	int tempGj = enemy->subDef(gj);
	calculate(tempGj, gj, enemy);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}

const char* CWarriorSkillNumber5::getName()
{
	return "�������һء�";
}

CWarriorSkillNumber4::CWarriorSkillNumber4()
{
	cd = 5;
}

void CWarriorSkillNumber4::Action(CHero* ally, CHero* enemy)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	int gj = ally->getAD();
	std::cout << ally->GetName() << "ʹ����" << getName();
	int tempRandom = getRandomInt();
	if (tempRandom % 100 < ally->getBJ()) {//����
		gj += (gj * ally->getBJValue() / 100);
		std::cout << "��������";
	}
	else {
		std::cout << "���У�";
	}
	int tempGj = enemy->subDef(gj);
	calculate(tempGj, gj, enemy);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}

const char* CWarriorSkillNumber4::getName()
{
	return "�����й��ʡ�";
}

CHealingSkillNumberThree::CHealingSkillNumberThree()
{
	cd = 4;
}

void CHealingSkillNumberThree::Action(CHero* ally, CHero* other)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	std::cout << ally->GetName() << "�����˻��ܹ��� " << getName();
	int random = getRandomIntRange(1, 10);
	float targetData = (float)ally->getAP();
	targetData += (targetData * random / 10);
	other->SetDef((int)targetData);
	std::cout << "������" << other->GetName() << "����" << targetData << "�㻤�ܣ�Ϊ�´η����ṩ�˱���\n";
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}

const char* CHealingSkillNumberThree::getName()
{
	return "������һ������";
}

CHealingSkillNumberFour::CHealingSkillNumberFour()
{
	cd = 3;
}

void CHealingSkillNumberFour::Action(CHero* ally, CHero* other)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	std::cout << ally->GetName() << "�����˼�Ѫ���� " << getName();
	int random = getRandomIntRange(1, 10);
	float targetData = (float)ally->getAP();
	targetData += (targetData * random / 10);
	other->healing((int)targetData);
	std::cout << "������" << other->GetName() << "����" << targetData << "��Ѫ��\n";
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}

const char* CHealingSkillNumberFour::getName()
{
	return "���������ǡ�";
}
