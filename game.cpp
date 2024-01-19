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
			.setQcd(3)
			.setRcd(5)
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
			.setQcd(3)
			.setRcd(5)
			.setName("��")
			.build();
		leftTeam.push_back(temp);
	}
	{
		CSupporterBuilder  sbuilder;
		CHero* temp = sbuilder
			.setHp(2000)
			.setAP(300)
			.setQcd(5)
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
			.setQcd(2)
			.setRcd(4)
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
			.setQcd(2)
			.setRcd(4)
			.setName("��Τ")
			.build();
		rightTeam.push_back(temp);
	}
	{
		CSupporterBuilder sbuilder;
		CHero* temp = sbuilder
			.setHp(2000)
			.setAP(200)
			.setQcd(3)
			.setName("��ڼ")
			.build();
		rightTeam.push_back(temp);
	}
}

void CGAME::choose(bool isLeft)
{
	auto& ourTeam = isLeft ? leftTeam : rightTeam;
	forEach(&ourTeam, &leftTeam, &rightTeam, [](CHero* target, auto ourTeam, auto enemyTeam) {
		if (dynamic_cast<CSupporter*>(target)) {//����Ǹ���
			bool onlySupporter = (*ourTeam).size() == 1;//���ֻʣ����
			if (onlySupporter) {//һ�����
				bool selfDestory = getRandomIntRange(1,0);
				if (selfDestory) {
					std::vector<CHero*>::iterator it = (*enemyTeam).begin();
					for (; it != (*enemyTeam).end(); it++)
					{
						(*it)->dead();
					}
				}
				else {
					(*target).dead();
				}
			}
			else {//��������
				std::vector<CHero*>::iterator it = (*ourTeam).begin();
				CHero* allay = 0;
				for (; it != (*ourTeam).end(); it++)
				{
					if (!dynamic_cast<CSupporter*>((*it))) {
						allay = (*it);
						break;
					}
				}
				target->Action(allay);
			}
		}
		else {
			CHero* enemy = (*enemyTeam)[getRandomIntRange((*enemyTeam).size() - 1, 0)];
			target->Action(enemy);
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
		std::cout << tempHero.GetName()
			<< "  HP��" << tempHero.getHp()
			<< "|DEF��" << tempHero.getDef()
			<< std::endl;
		return false;
		});

	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

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
		round++;
		system("pause");
	}
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
