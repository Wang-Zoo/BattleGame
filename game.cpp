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
		CWarriorBuilder wbuilder;
		CHero* temp = wbuilder
			.setHp(3000)
			.setAD(300)
			.setBJ(30)
			.setQcd(3)
			.setRcd(5)
			.setName("赵云")
			.build();
		leftTeam.push_back(temp);

		CSupporterBuilder  sbuilder;
		temp = sbuilder
			.setHp(2000)
			.setAP(300)
			.setQcd(5)
			.setName("蔡文姬")
			.build();

		leftTeam.push_back(temp);
	}
	//创建右边队伍
	{
		CWarriorBuilder wbuilder;
		CHero* temp = wbuilder
			.setHp(3500)
			.setAD(200)
			.setBJ(30)
			.setQcd(2)
			.setRcd(4)
			.setName("马超")
			.build();
		rightTeam.push_back(temp);

		CSupporterBuilder sbuilder;
		temp = sbuilder
			.setHp(2000)
			.setAP(200)
			.setQcd(3)
			.setName("杨玉环")
			.build();
		rightTeam.push_back(temp);
	}
}

void CGAME::Run()
{
	int round = 0;
	bool leftBattle = true;
	while (1) {
		std::cout << "=======================第" << ++round << "回合========================\n";
		//左边战队
		if (leftBattle) {
			CHero* leftHero = leftTeam[CRandom::getInstance().getRandomIntRange(leftTeam.size() - 1, 0)];
			CSupporter* leftSupporter = dynamic_cast<CSupporter*>(leftHero);
			//左边抽到了辅助
			if (leftSupporter) {
				leftHero->Action(leftTeam[CRandom::getInstance().getRandomIntRange(leftTeam.size() - 1, 0)]);
			}
			else {
				leftHero->Action(rightTeam[CRandom::getInstance().getRandomIntRange(rightTeam.size() - 1, 0)]);
			}
		}
		//右边战队
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
			std::cout << tempHero.GetName() << "剩余血量：" << tempHero.getHp()<<std::endl;
			});
		forEach(&rightTeam, [](CHero* temp) {
			CHero& tempHero = *temp;
			tempHero.Run();
			std::cout << tempHero.GetName() << "剩余血量：" << tempHero.getHp() << std::endl;
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
