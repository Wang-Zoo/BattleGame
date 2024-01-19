#include "game.h"
#include "builder.h"
#include "random.h"
#include "iostream"
#include "tool.h"

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

void CGAME::Init()
{
	//������߶���
	createLeftTeam();
	//�����ұ߶���
	createRightTeam();
}

void CGAME::Run()
{
	int round = 0;
	bool leftBattle = true;
	while (1) {
		std::cout << "=======================��" << ++round << "�غ�========================\n";
		//���ս��	
		choose(true);
		//�ұ�ս��
		choose(false);
		//��ӡѪ��
		forEach(&leftTeam, [](CHero* temp) {
			CHero& tempHero = *temp;
			tempHero.Run();
			std::cout << tempHero.GetName() << "ʣ��Ѫ����" << tempHero.getHp() << std::endl;
			return false;
			});
		forEach(&rightTeam, [](CHero* temp) {
			CHero& tempHero = *temp;
			tempHero.Run();
			std::cout << tempHero.GetName() << "ʣ��Ѫ����" << tempHero.getHp() << std::endl;
			return false;
			});
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
