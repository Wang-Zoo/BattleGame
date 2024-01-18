#include "game.h"
#include "builder.h"
#include "random.h"
/*
սʿ��Q���ٹ��� ����������Ч����cd 3s ��R �ػ�����������Ч����cd 5s��A ��ͨ�������ޱ���
������Q��һ�����ѼӴ���Ѫ��cd 5s��R��������Ѽ�����Ѫ��cd 5s��A ��ͨ����
̹�ˣ�Q���������һ�����ܣ��ܹ�����Ѽ���һ�����ܹ���ֵ����Ч��һ���Եģ�cd 5s, 
*/

void CGAME::Init()
{
	//������߶���
	{
		CWarriorBuilder builder;
		CHero* temp = builder
			.setAD(30)
			.setBJ(30)
			.setName("����")
			.build();
		leftTeam.push_back(temp);
	}
	//�����ұ߶���
	{
		CWarriorBuilder builder;
		CHero* temp = builder
			.setAD(30)
			.setBJ(30)
			.setName("��")
			.build();
		rightTeam.push_back(temp);
	}
}

void CGAME::Run()
{
	while (1) {
		//����ȹ���
		
		int targetIndex = CRandom::getInstance().getRandomIntRange(rightTeam.size(), 0);
		CHero *temp = rightTeam[targetIndex];

		//�ұߺ󹥻�
	}
}

void CGAME::End()
{
	
}
