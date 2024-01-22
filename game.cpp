#include "game.h"
#include "builder.h"
#include "random.h"
#include "iostream"
#include "tool.h"
#include "Windows.h"
#include "config.h"
void CGAME::createLeftTeam()
{
	CTEAM* team = new CTEAM(FOREGROUND_GREEN,"蜀国",NO_ONE_TEAM);
	{
		CWarriorBuilder wbuilder;
		CHero* temp = wbuilder
			.setHp(3000)
			.setAD(300)
			.setBJ(30)
			.addSkill((CSkill*)(new CWarriorSkillNumber1))
			.addSkill((CSkill*)(new CWarriorSkillNumber2))
			.addSkill((CSkill*)(new CNormalAttack))
			.setName("【赵云】")
			.build(NO_ONE_TEAM);
		team->addHero(temp);
	}
	{
		CWarriorBuilder wbuilder;
		CHero* temp = wbuilder
			.setHp(3000)
			.setAD(300)
			.setBJ(30)
			.addSkill((CSkill*)(new CWarriorSkillNumber3))
			.addSkill((CSkill*)(new CWarriorSkillNumber4))
			.addSkill((CSkill*)(new CNormalAttack))
			.setName("【马超】")
			.build(NO_ONE_TEAM);
		team->addHero(temp);
	}
	{
		CSupporterBuilder  sbuilder;
		CHero* temp = sbuilder
			.setHp(4000)
			.setAP(300)
			.addSkill((CSkill*)(new CHealingSkillNumberOne))
			.addSkill((CSkill*)(new CHealingSkillNumberTwo))
			.setName("【庞统】")
			.build(NO_ONE_TEAM);

		team->addHero(temp);
	}
	teams.push_back(team);
}

void CGAME::createRightTeam()
{
	CTEAM* team = new CTEAM(FOREGROUND_BLUE,"魏国", NO_THREE_TEAM);
	{
		CWarriorBuilder wbuilder;
		CHero* temp = wbuilder
			.setHp(1000)
			.setAD(200)
			.setBJ(30)
			.addSkill((CSkill*)(new CWarriorSkillNumber5))
			.addSkill((CSkill*)(new CWarriorSkillNumber6))
			.addSkill((CSkill*)(new CNormalAttack))
			.setName("【张辽】")
			.build(NO_THREE_TEAM);
		team->addHero(temp);
	}
	{
		CWarriorBuilder wbuilder;
		CHero* temp = wbuilder
			.setHp(1000)
			.setAD(200)
			.setBJ(30)
			.addSkill((CSkill*)(new CWarriorSkillNumber7))
			.addSkill((CSkill*)(new CWarriorSkillNumber8))
			.addSkill((CSkill*)(new CNormalAttack))
			.setName("【典韦】")
			.build(NO_THREE_TEAM);
		team->addHero(temp);
	}
	{
		CSupporterBuilder sbuilder;
		CHero* temp = sbuilder
			.setHp(5000)
			.setAP(200)
			.addSkill((CSkill*)(new CHealingSkillNumberThree))
			.addSkill((CSkill*)(new CHealingSkillNumberFour))
			.setName("【贾诩】")
			.build(NO_THREE_TEAM);
		team->addHero(temp);
	}
	teams.push_back(team);
}

void CGAME::createMiddleTeam()
{
	CTEAM* team = new CTEAM(FOREGROUND_RED, "吴国", NO_TWO_TEAM);
	{
		CWarriorBuilder wbuilder;
		CHero* temp = wbuilder
			.setHp(1000)
			.setAD(200)
			.setBJ(30)
			.addSkill((CSkill*)(new CWarriorSkillNumber5))
			.addSkill((CSkill*)(new CWarriorSkillNumber6))
			.addSkill((CSkill*)(new CNormalAttack))
			.setName("【孙策】")
			.build(NO_TWO_TEAM);
		team->addHero(temp);
	}
	{
		CWarriorBuilder wbuilder;
		CHero* temp = wbuilder
			.setHp(1000)
			.setAD(200)
			.setBJ(30)
			.addSkill((CSkill*)(new CWarriorSkillNumber7))
			.addSkill((CSkill*)(new CWarriorSkillNumber8))
			.addSkill((CSkill*)(new CNormalAttack))
			.setName("【甘宁】")
			.build(NO_TWO_TEAM);
		team->addHero(temp);
	}
	{
		CSupporterBuilder sbuilder;
		CHero* temp = sbuilder
			.setHp(5000)
			.setAP(200)
			.addSkill((CSkill*)(new CHealingSkillNumberThree))
			.addSkill((CSkill*)(new CHealingSkillNumberFour))
			.setName("【鲁肃】")
			.build(NO_TWO_TEAM);
		team->addHero(temp);
	}
	teams.push_back(team);
}

void CGAME::createFourthTeam()
{
	CTEAM* team = new CTEAM(FOREGROUND_RED| FOREGROUND_BLUE, "吕布军", NO_FOUR_TEAM);
	{
		CWarriorBuilder wbuilder;
		CHero* temp = wbuilder
			.setHp(1000)
			.setAD(200)
			.setBJ(30)
			.addSkill((CSkill*)(new CWarriorSkillNumber5))
			.addSkill((CSkill*)(new CWarriorSkillNumber6))
			.addSkill((CSkill*)(new CNormalAttack))
			.setName("【吕布】")
			.build(NO_FOUR_TEAM);
		team->addHero(temp);
	}
	{
		CWarriorBuilder wbuilder;
		CHero* temp = wbuilder
			.setHp(1000)
			.setAD(200)
			.setBJ(30)
			.addSkill((CSkill*)(new CWarriorSkillNumber7))
			.addSkill((CSkill*)(new CWarriorSkillNumber8))
			.addSkill((CSkill*)(new CNormalAttack))
			.setName("【高顺】")
			.build(NO_FOUR_TEAM);
		team->addHero(temp);
	}
	{
		CSupporterBuilder sbuilder;
		CHero* temp = sbuilder
			.setHp(5000)
			.setAP(200)
			.addSkill((CSkill*)(new CHealingSkillNumberThree))
			.addSkill((CSkill*)(new CHealingSkillNumberFour))
			.setName("【陈宫】")
			.build(NO_FOUR_TEAM);
		team->addHero(temp);
	}
	teams.push_back(team);
}

void CGAME::createFifthTeam()
{
	CTEAM* team = new CTEAM(FOREGROUND_RED| FOREGROUND_GREEN, "袁绍军", NO_FIVE_TEAM);
	{
		CWarriorBuilder wbuilder;
		CHero* temp = wbuilder
			.setHp(1000)
			.setAD(200)
			.setBJ(30)
			.addSkill((CSkill*)(new CWarriorSkillNumber5))
			.addSkill((CSkill*)(new CWarriorSkillNumber6))
			.addSkill((CSkill*)(new CNormalAttack))
			.setName("【文丑】")
			.build(NO_FIVE_TEAM);
		team->addHero(temp);
	}
	{
		CWarriorBuilder wbuilder;
		CHero* temp = wbuilder
			.setHp(1000)
			.setAD(200)
			.setBJ(30)
			.addSkill((CSkill*)(new CWarriorSkillNumber7))
			.addSkill((CSkill*)(new CWarriorSkillNumber8))
			.addSkill((CSkill*)(new CNormalAttack))
			.setName("【颜良】")
			.build(NO_FIVE_TEAM);
		team->addHero(temp);
	}
	{
		CSupporterBuilder sbuilder;
		CHero* temp = sbuilder
			.setHp(5000)
			.setAP(200)
			.addSkill((CSkill*)(new CHealingSkillNumberThree))
			.addSkill((CSkill*)(new CHealingSkillNumberFour))
			.setName("【田丰】")
			.build(NO_FIVE_TEAM);
		team->addHero(temp);
	}
	teams.push_back(team);
}

int CGAME::getRandomTeamNum(int self)
{
	int index = -1;
	while (index < 0 || index == self|| teams[index]->isAllDead()) {
		index = getRandomIntRange(teams.size() - 1, 0);	
	}
	return index;
}

void CGAME::Init()
{
	createLeftTeam();
	createMiddleTeam();
	createRightTeam();
	createFourthTeam();
	createFifthTeam();
}

void CGAME::Run()
{
	int round = 1;
	bool leftBattle = true;
	std::cout << "=======================游戏开始========================\n";
	std::cout << "=========起始数据==========\n";
	for (const auto& temp : teams) {
		temp->displayTeamInfo();
	}
	system("pause");

	while (1) {
		std::cout << "=======================第" << round << "回合开始========================\n";
		for (const auto&team:teams)
		{
			if (team->isAllDead()) {
				continue;
			}
			team->battle(this);
		}

		std::cout << "=======================第" << round << "回合结算========================\n";
		for (const auto& temp : teams) {
			temp->displayTeamInfo();
		}
		std::cout << "=======================第" << round<< "回合结束========================\n";
		int aliveTeam = 0;
		int index = 0;
		int aliveIndex = -1;
		for (const auto& team : teams)
		{
			if (!team->isAllDead()) {
				aliveTeam++;
				aliveIndex = index;
			}
			index++;
		}
		if (aliveTeam == 1) {
			std::cout << "=======================游戏结束，"<< teams[aliveIndex]->getName()<<"胜利========================\n";
			break;
		}
		round++;
		system("pause");
	}

	system("pause");
}

void CGAME::End()
{
	for (const auto& temp : teams) {
		delete temp;
	}
}

CHero* CGAME::getEnemy(int selfTeamNum)
{
	auto enemyTeam = teams[getRandomTeamNum(selfTeamNum)];
	return enemyTeam->findAlive();
}

CTEAM* CGAME::getTeam(int selfTeamNum)
{
	auto enemyTeam = teams[getRandomTeamNum(selfTeamNum)];
	return enemyTeam;
}

void CGAME::clearTraitor(CHero* traitor)
{
	const char * name = teams[traitor->getTeamNum()]->getName();
	teams[traitor->getTeamNum()]->addHero(traitor);
	std::cout << traitor->GetName() << "重新加入了" << name << "\n";
	
}
