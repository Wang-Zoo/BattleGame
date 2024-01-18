#include "game.h"
#include "builder.h"
#include "random.h"
#include "iostream"
/*
սʿ��Q���ٹ��� ����������Ч����cd 3s ��R �ػ�����������Ч����cd 5s��A ��ͨ�������ޱ���
������Q��һ�����ѼӴ���Ѫ��cd 5s��R��������Ѽ�����Ѫ��cd 5s��A ��ͨ����
̹�ˣ�Q���������һ�����ܣ��ܹ�����Ѽ���һ�����ܹ���ֵ����Ч��һ���Եģ�cd 5s, 
*/

void CGAME::forEach(std::vector<CHero*> *origins, HeroCallback callback)
{
	std::vector<CHero*>::iterator it = (*origins).begin();

	for (;it!=(*origins).end();it++)
	{
		callback(*it);
	}
}

void CGAME::Init()
{
	//������߶���
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

		CSupporterBuilder  sbuilder;
		temp = sbuilder
			.setHp(2000)
			.setAP(300)
			.setQcd(5)
			.setName("���ļ�")
			.build();

		leftTeam.push_back(temp);
	}
	//�����ұ߶���
	{
		CWarriorBuilder wbuilder;
		CHero* temp = wbuilder
			.setHp(3500)
			.setAD(200)
			.setBJ(30)
			.setQcd(2)
			.setRcd(4)
			.setName("��")
			.build();
		rightTeam.push_back(temp);

		CSupporterBuilder sbuilder;
		temp = sbuilder
			.setHp(2000)
			.setAP(200)
			.setQcd(3)
			.setName("����")
			.build();
		rightTeam.push_back(temp);
	}
}

void CGAME::Run()
{
	int round = 0;
	bool leftBattle = true;
	while (1) {
		std::cout << "=======================��" << ++round << "�غ�========================\n";
		//���ս��
		if (leftBattle) {
			CHero* leftHero = leftTeam[CRandom::getInstance().getRandomIntRange(leftTeam.size() - 1, 0)];
			CSupporter* leftSupporter = dynamic_cast<CSupporter*>(leftHero);
			//��߳鵽�˸���
			if (leftSupporter) {
				leftHero->Action(leftTeam[CRandom::getInstance().getRandomIntRange(leftTeam.size() - 1, 0)]);
			}
			else {
				leftHero->Action(rightTeam[CRandom::getInstance().getRandomIntRange(rightTeam.size() - 1, 0)]);
			}
		}
		//�ұ�ս��
		else {
			CHero* rightHero = rightTeam[CRandom::getInstance().getRandomIntRange(rightTeam.size() - 1, 0)];
			CSupporter* rightSupporter = dynamic_cast<CSupporter*>(rightHero);
			if (rightSupporter) {
				rightHero->Action(rightTeam[CRandom::getInstance().getRandomIntRange(rightTeam.size() - 1, 0)]);
			}
			else {
				rightHero->Action(leftTeam[CRandom::getInstance().getRandomIntRange(leftTeam.size() - 1, 0)]);
			}
		}

		forEach(&leftTeam, [](CHero* temp) {
			CHero& tempHero = *temp;
			tempHero.Run();  
			std::cout << tempHero.GetName() << "ʣ��Ѫ����" << tempHero.getHp()<<std::endl;
			});
		forEach(&rightTeam, [](CHero* temp) {
			CHero& tempHero = *temp;
			tempHero.Run();
			std::cout << tempHero.GetName() << "ʣ��Ѫ����" << tempHero.getHp() << std::endl;
			});
		leftBattle = !leftBattle;
		system("pause");
	}
}

void CGAME::End()
{
	
	forEach(&leftTeam, [](CHero* temp) {
		delete temp;
		});
	forEach(&rightTeam, [](CHero* temp) {
		delete temp;
		});

	leftTeam.clear();
	rightTeam.clear();
}
