#include"team.h"
#include"tool.h"
#include"supporter.h"
#include "warrior.h"
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
	std::cout << supporter->GetName() << "孤军奋战，他准备发动【毁天灭地】来一把绝地求生\n";
	system("pause");

	bool selfDestory = getRandomIntRange(1, 0);
	if (selfDestory) {
		std::cout << supporter->GetName() << "发动成功，"<<enemyTeam->getName()<<"被全军覆没！！！！" << "\n";
		enemyTeam->allDead(supporter->GetName());
	}
	else {
		supporter->dead();
		std::cout << supporter->GetName() << "求生失败！饮恨而终\n";
	}
}

CTEAM::CTEAM(int teamColor,const char * name,int teamNum)
{
	this->teamColor = teamColor;
	this->teamName = name;
	this->teamNum = teamNum;
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
	//先判断是否还有存活着的
	if (getAliveNum()) {
		//随机找到一个没有死亡的敌军
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

void CTEAM::battle(CGetEnemyInter* inter)
{
	auto it = heros.begin();
	for (;it!=heros.end();) {

		if ((*it)->getTeamNum() != teamNum) {
			CHero* traitor = (*it);
			std::cout <<teamName << "清除了叛徒"<<traitor->GetName()<<"\n";
			inter->clearTraitor(traitor);
			it = heros.erase(it);
		}
		else {
			it++;
		}
	}

	for (const auto&target:heros)
	{
		if (!target->isAlive()) {
			continue;
		}
		if (dynamic_cast<CSupporter*>(target)) {//如果是辅助
			if (getAliveNum()==1) {
				if (getPercent(6)) {
					CHero* targetW = inter->findEnemyWarrior(teamNum);
					if (targetW) {
						target->Action(targetW);
					}
				}
				else {
					randomDestory(target, inter->getTeam(teamNum));
				}
			}
			else {//辅助队友
				target->Action(findWarroier());
			}
		}
		else {
			CHero* enemy = inter->getEnemy(teamNum);
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
	std::cout << enemyName << "梭哈成功！绝地反击\n";
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
				<< "  HP：" << tempHero.getHp()
				<< " | DEF：" << tempHero.getDef();
			auto skills = *(tempHero.getSkills());
			std::vector<CSkill*>::iterator it = skills.begin();
			for (; it != skills.end(); it++)
			{
				std::cout << " " << (*it)->getName() << "CD:" << (*it)->getCCD();
			}
			std::cout << std::endl;
		}
		else {
			std::cout << tempHero.GetName() << "  已经洗白\n";
		}
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}

const char* CTEAM::getName()
{
	return teamName;
}

bool CTEAM::onlySupproterAlive()
{
	if(getAliveNum()==1){
		bool isSupproter = false;
		for (const auto& hero :heros)
		{
			if (dynamic_cast<CSupporter*>(hero)&&hero->isAlive()) {
				isSupproter = true;
				break;
			}
		}
		return isSupproter;
	}
	return false;
}

CHero* CTEAM::findTargetWarroier()
{
	for (const auto& hero:heros)
	{
		if (dynamic_cast<CWarrior*>(hero)&&hero->isAlive()) {
			return hero;
		}
	}

	return nullptr;
}

int CTEAM::getTeamNum()
{
	return teamNum;
}

