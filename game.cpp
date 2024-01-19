#include "game.h"
#include "builder.h"
#include "random.h"
#include "iostream"
#include "tool.h"
#include "Windows.h"

void CGAME::createLeftTeam()
{
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
		leftTeam.push_back(temp);
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
		leftTeam.push_back(temp);
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

		leftTeam.push_back(temp);
	}
}

void CGAME::createRightTeam()
{
	{
		CWarriorBuilder wbuilder;
		CHero* temp = wbuilder
			.setHp(3500)
			.setAD(200)
			.setBJ(30)
			.addSkill((CSkill*)(new CWarriorSkillNumber5))
			.addSkill((CSkill*)(new CWarriorSkillNumber6))
			.addSkill((CSkill*)(new CNormalAttack))
			.setName("����")
			.build();
		rightTeam.push_back(temp);
	}
	{
		CWarriorBuilder wbuilder;
		CHero* temp = wbuilder
			.setHp(3500)
			.setAD(200)
			.setBJ(30)
			.addSkill((CSkill*)(new CWarriorSkillNumber7))
			.addSkill((CSkill*)(new CWarriorSkillNumber8))
			.addSkill((CSkill*)(new CNormalAttack))
			.setName("��Τ")
			.build();
		rightTeam.push_back(temp);
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
		rightTeam.push_back(temp);
	}
}

void CGAME::choose(bool isLeft)
{
	auto& ourTeam = isLeft ? leftTeam : rightTeam;
	forEach(&ourTeam, &leftTeam, &rightTeam, [](CHero* target, auto ourTeam, auto enemyTeam) {
		if (!target->isAlive()) {
			return;
		}
		if (dynamic_cast<CSupporter*>(target)) {//����Ǹ���

			auto allIt = (*ourTeam).begin();
			int aliveCount = 1;
			for (;allIt!=(*ourTeam).end();allIt++)
			{
				if ((*allIt)->isAlive()) {
					aliveCount++;
				}
			}
			bool onlySupporter = aliveCount==1;//���ֻʣ����
			if (onlySupporter) {//һ�����

				std::cout << target->GetName() << "�¾���ս����׼��������������ء���һ�����\n";
				system("pause");

				bool selfDestory = getRandomIntRange(1,0);
				if (selfDestory) {
					std::vector<CHero*>::iterator it = (*enemyTeam).begin();
					for (; it != (*enemyTeam).end(); it++)
					{
						(*it)->dead();
					}
					std::cout << target->GetName() << "����ɹ������ط���\n";
				}
				else {
					(*target).dead();
					std::cout << target->GetName() << "���ʧ�ܣ����޶���\n";
				}
			}
			else {//��������
				std::vector<CHero*>::iterator it = (*ourTeam).begin();
				CHero* allay = 0;

				while (!allay || dynamic_cast<CSupporter*>(allay) || !allay->isAlive()) {
					allay = (*ourTeam)[getRandomIntRange((*ourTeam).size() - 1, 0)];
				}

				target->Action(allay);
			}
		}
		else {

			auto it = (*enemyTeam).begin();
			bool isAll = true;
			for (; it != (*enemyTeam).end(); it++)
			{
				if ((*it)->isAlive()) {
					isAll = false;
					break;
				}
			}
			if (!isAll) {
				//�ҵ�һ��û�������ĵо�
				CHero* enemy = 0;
				while (!enemy || !enemy->isAlive()) {
					enemy = (*enemyTeam)[getRandomIntRange((*enemyTeam).size() - 1, 0)];
				}
				target->Action(enemy);
			}
		}
		});
}

void CGAME::displayHero(bool isLeft)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, isLeft? (FOREGROUND_RED | FOREGROUND_INTENSITY):(FOREGROUND_BLUE | FOREGROUND_INTENSITY));

	forEach(isLeft?&leftTeam:&rightTeam, [](CHero* temp) {
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


		return false;
		});

	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

}

bool CGAME::isAllDead(bool isLeft)
{
	auto targetTeam = isLeft ? leftTeam :rightTeam;
	auto it = targetTeam.begin();
	bool isAll = true;
	for (;it!=targetTeam.end();it++)
	{
		if ((*it)->isAlive()) {
			isAll = false;
			break;
		}
	}
	return isAll;
}

void CGAME::Init()
{
	//������߶���
	createLeftTeam();
	//�����ұ߶���
	createRightTeam();
}

void CGAME::Run()
{
	int round = 1;
	bool leftBattle = true;
	std::cout << "=======================��Ϸ��ʼ========================\n";
	std::cout << "=========�췽����==========\n";
	//��ӡ���ս��Ѫ��
	displayHero(true);
	std::cout << "=========��������==========\n";
	//��ӡ�ұ�ս��Ѫ��
	displayHero(false);
	system("pause");

	while (1) {
		std::cout << "=======================��" << round << "�غϿ�ʼ========================\n";
		//���ս��	
		choose(true);
		//�ұ�ս��
		choose(false);
		std::cout << "=======================��" << round << "�غϽ���========================\n";
		//��ӡ���ս��Ѫ��
		displayHero(true);
		//��ӡ�ұ�ս��Ѫ��
		displayHero(false);
		std::cout << "=======================��" << round<< "�غϽ���========================\n";

		if (isAllDead(true)) {
			std::cout << "=======================��Ϸ����������ʤ��========================\n";
			break;
		}
		else if (isAllDead(false)) {
			std::cout << "=======================��Ϸ�������췽ʤ��========================\n";
			break;
		}

		round++;
		system("pause");
	}

	system("pause");
}

void CGAME::End()
{

	forEach(&leftTeam, [](CHero* temp) {
		delete temp;
		return false;
		});
	forEach(&rightTeam, [](CHero* temp) {
		delete temp;
		return false;
		});

	leftTeam.clear();
	rightTeam.clear();
}
