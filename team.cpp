#include"team.h"
#include"tool.h"
#include"supporter.h"
#include"iostream"
#include"Windows.h"

bool CTEAM::onlySupporter()
{
	return false;
}

int CTEAM::getAliveNum()
{
	auto allIt = heros.begin();
	int aliveCount = 0;
	for (; allIt != heros.end(); allIt++)
	{
		if ((*allIt)->isAlive()) {
			aliveCount++;
		}
	}
	return aliveCount;
}

CHero* CTEAM::findWarroier()
{
	CHero* allay = 0;
	while (!allay || dynamic_cast<CSupporter*>(allay) || !allay->isAlive()) {
		allay = heros[getRandomIntRange(heros.size() - 1, 0)];
	}
	return allay;
}

void CTEAM::randomDestory(CHero* supporter, CTEAM* enemyTeam)
{
	std::cout << supporter->GetName() << "�¾���ս����׼��������������ء���һ�����\n";
	system("pause");

	bool selfDestory = getRandomIntRange(1, 0);
	if (selfDestory) {
		enemyTeam->allDead(supporter->GetName());
	}
	else {
		supporter->dead();
		std::cout << supporter->GetName() << "���ʧ�ܣ����޶���\n";
	}
}

CTEAM::CTEAM(int teamColor,const char * name)
{
	this->teamColor = teamColor;
	this->teamName = name;
}

CTEAM::~CTEAM()
{
	for (const auto&temp:heros)
	{
		delete temp;
	}
}

void CTEAM::addHero(CHero* hero)
{
	heros.push_back(hero);
}

CHero* CTEAM::findAlive()
{
	auto it = heros.begin();
	bool isAll = true;
	//���ж��Ƿ��д���ŵ�
	if (getAliveNum()) {
		//����ҵ�һ��û�������ĵо�
		CHero* enemy = 0;
		while (!enemy || !enemy->isAlive()) {
			enemy = heros[getRandomIntRange(heros.size() - 1, 0)];
		}
		return enemy;
	}
	else {
		return nullptr;
	}

}

void CTEAM::battle(CTEAM* enemyTeam)
{
	for (const auto&target:heros)
	{
		if (!target->isAlive()) {
			continue;
		}
		if (dynamic_cast<CSupporter*>(target)) {//����Ǹ���
			if (getAliveNum()==1) {//һ�����
				randomDestory(target,enemyTeam);
			}
			else {//��������
				target->Action(findWarroier());
			}
		}
		else {
			CHero* enemy = enemyTeam->findAlive();
			target->Action(enemy);
		}
	}
}

void CTEAM::allDead(const char *enemyName)
{
	for (const auto&temp:heros)
	{
		temp->dead();
	}
	std::cout << enemyName << "����ɹ������ط���\n";
}

bool CTEAM::isAllDead()
{
	return getAliveNum() == 0;
}

void CTEAM::displayTeamInfo()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,  (teamColor | FOREGROUND_INTENSITY));
	for (const auto&temp:heros)
	{
		CHero& tempHero = *temp;
		tempHero.Run();
		if (tempHero.isAlive()) {
			std::cout << tempHero.GetName()
				<< "  HP��" << tempHero.getHp()
				<< " | DEF��" << tempHero.getDef();
			auto skills = *(tempHero.getSkills());
			std::vector<CSkill*>::iterator it = skills.begin();
			for (; it != skills.end(); it++)
			{
				std::cout << " " << (*it)->getName() << "CD:" << (*it)->getCCD();
			}
			std::cout << std::endl;
		}
		else {
			std::cout << tempHero.GetName() << "  �Ѿ�ϴ��\n";
		}
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}

const char* CTEAM::getName()
{
	return teamName;
}
