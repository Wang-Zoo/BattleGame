#include "game.h"
#include "builder.h"
#include "random.h"
#include "iostream"
/*
战士：Q快速攻击 ，少量暴击效果，cd 3s ：R 重击，大量暴击效果，cd 5s；A 普通攻击，无暴击
辅助：Q给一个队友加大量血，cd 5s；R给多个队友加少量血，cd 5s，A 普通攻击
坦克：Q给队友添加一个护盾，能够帮队友减少一次所受攻击值，该效果一次性的，cd 5s, 
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
	//创建左边队伍
	{
		CWarriorBuilder builder;
		CHero* temp = builder
			.setHp(3000)
			.setDef(3000)
			.setAD(300)
			.setBJ(30)
			.setQcd(3)
			.setRcd(5)
			.setName("赵云")
			.build();
		leftTeam.push_back(temp);
	}
	//创建右边队伍
	{
		CWarriorBuilder builder;
		CHero* temp = builder
			.setHp(3500)
			.setDef(3000)
			.setAD(200)
			.setBJ(30)
			.setQcd(2)
			.setRcd(4)
			.setName("马超")
			.build();
		rightTeam.push_back(temp);
	}
}

void CGAME::Run()
{
	int round = 0;
	while (1) {
		std::cout << "=======================第" << ++round << "回合========================\n";
		//左右队伍各选一个英雄
		int leftIndex = CRandom::getInstance().getRandomIntRange(leftTeam.size()-1, 0);
		CHero *leftHero = leftTeam[leftIndex];
		int rightIndex = CRandom::getInstance().getRandomIntRange(rightTeam.size()-1, 0);
		CHero* rightHero = rightTeam[rightIndex];

		leftHero->Action(rightHero);
		rightHero->Action(leftHero);

		forEach(&leftTeam, [](CHero* temp) {
			CHero& tempHero = *temp;
			tempHero.Run();
			std::cout << tempHero.GetName() << "剩余血量：" << tempHero.getHp()<<std::endl;
			});
		forEach(&rightTeam, [](CHero* temp) {
			CHero& tempHero = *temp;
			tempHero.Run();
			std::cout << tempHero.GetName() << "剩余血量：" << tempHero.getHp() << std::endl;
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
