#include "game.h"
#include "builder.h"
#include "random.h"
#include "iostream"
#include "tool.h"
#include "Windows.h"

void CGAME::createLeftTeam()
{
	CTEAM* team = new CTEAM(FOREGROUND_GREEN,"���");
	{
		CWarriorBuilder wbuilder;
		CHero* temp = wbuilder
			.setHp(3000)
			.setAD(300)
			.setBJ(30)
			.addSkill((CSkill*)(new CWarriorSkillNumber1))
			.addSkill((CSkill*)(new CWarriorSkillNumber2))
			.addSkill((CSkill*)(new CNormalAttack))
			.setName("����")
			.build();
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
			.setName("��")
			.build();
		team->addHero(temp);
	}
	{
		CSupporterBuilder  sbuilder;
		CHero* temp = sbuilder
			.setHp(4000)
			.setAP(300)
			.addSkill((CSkill*)(new CHealingSkillNumberOne))
			.addSkill((CSkill*)(new CHealingSkillNumberTwo))
			.setName("��ͳ")
			.build();

		team->addHero(temp);
	}
	teams.push_back(team);
}

void CGAME::createRightTeam()
{
	CTEAM* team = new CTEAM(FOREGROUND_BLUE,"κ��");
	{
		CWarriorBuilder wbuilder;
		CHero* temp = wbuilder
			.setHp(1000)
			.setAD(200)
			.setBJ(30)
			.addSkill((CSkill*)(new CWarriorSkillNumber5))
			.addSkill((CSkill*)(new CWarriorSkillNumber6))
			.addSkill((CSkill*)(new CNormalAttack))
			.setName("����")
			.build();
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
			.setName("��Τ")
			.build();
		team->addHero(temp);
	}
	{
		CSupporterBuilder sbuilder;
		CHero* temp = sbuilder
			.setHp(5000)
			.setAP(200)
			.addSkill((CSkill*)(new CHealingSkillNumberThree))
			.addSkill((CSkill*)(new CHealingSkillNumberFour))
			.setName("��ڼ")
			.build();
		team->addHero(temp);
	}
	teams.push_back(team);
}

void CGAME::createMiddleTeam()
{
	CTEAM* team = new CTEAM(FOREGROUND_RED, "���");
	{
		CWarriorBuilder wbuilder;
		CHero* temp = wbuilder
			.setHp(1000)
			.setAD(200)
			.setBJ(30)
			.addSkill((CSkill*)(new CWarriorSkillNumber5))
			.addSkill((CSkill*)(new CWarriorSkillNumber6))
			.addSkill((CSkill*)(new CNormalAttack))
			.setName("���")
			.build();
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
			.setName("����")
			.build();
		team->addHero(temp);
	}
	{
		CSupporterBuilder sbuilder;
		CHero* temp = sbuilder
			.setHp(5000)
			.setAP(200)
			.addSkill((CSkill*)(new CHealingSkillNumberThree))
			.addSkill((CSkill*)(new CHealingSkillNumberFour))
			.setName("³��")
			.build();
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
}

void CGAME::Run()
{
	int round = 1;
	bool leftBattle = true;
	std::cout << "=======================��Ϸ��ʼ========================\n";
	std::cout << "=========��ʼ����==========\n";
	for (const auto& temp : teams) {
		temp->displayTeamInfo();
	}
	system("pause");

	while (1) {
		std::cout << "=======================��" << round << "�غϿ�ʼ========================\n";
		int num = 0;
		for (const auto&team:teams)
		{
			if (team->isAllDead()) {
				continue;
			}
			auto enemyTeam = teams[getRandomTeamNum(num)];
			team->battle(enemyTeam);
			num++;
		}

		std::cout << "=======================��" << round << "�غϽ���========================\n";
		for (const auto& temp : teams) {
			temp->displayTeamInfo();
		}
		std::cout << "=======================��" << round<< "�غϽ���========================\n";
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
			std::cout << "=======================��Ϸ������"<< teams[aliveIndex]->getName()<<"ʤ��========================\n";
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
