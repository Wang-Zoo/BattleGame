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
		CWarriorBuilder builder;
		CHero* temp = builder
			.setHp(3000)
			.setDef(3000)
			.setAD(300)
			.setBJ(30)
			.setQcd(3)
			.setRcd(5)
			.setName("����")
			.build();
		leftTeam.push_back(temp);
	}
	//�����ұ߶���
	{
		CWarriorBuilder builder;
		CHero* temp = builder
			.setHp(3500)
			.setDef(3000)
			.setAD(200)
			.setBJ(30)
			.setQcd(2)
			.setRcd(4)
			.setName("��")
			.build();
		rightTeam.push_back(temp);
	}
}

void CGAME::Run()
{
	int round = 0;
	while (1) {
		std::cout << "=======================��" << ++round << "�غ�========================\n";
		//���Ҷ����ѡһ��Ӣ��
		int leftIndex = CRandom::getInstance().getRandomIntRange(leftTeam.size()-1, 0);
		CHero *leftHero = leftTeam[leftIndex];
		int rightIndex = CRandom::getInstance().getRandomIntRange(rightTeam.size()-1, 0);
		CHero* rightHero = rightTeam[rightIndex];

		leftHero->Action(rightHero);
		rightHero->Action(leftHero);

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
