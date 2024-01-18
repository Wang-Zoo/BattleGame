#include "game.h"
#include "builder.h"
#include "random.h"
/*
战士：Q快速攻击 ，少量暴击效果，cd 3s ：R 重击，大量暴击效果，cd 5s；A 普通攻击，无暴击
辅助：Q给一个队友加大量血，cd 5s；R给多个队友加少量血，cd 5s，A 普通攻击
坦克：Q给队友添加一个护盾，能够帮队友减少一次所受攻击值，该效果一次性的，cd 5s, 
*/

void CGAME::Init()
{
	//创建左边队伍
	{
		CWarriorBuilder builder;
		CHero* temp = builder
			.setAD(30)
			.setBJ(30)
			.setName("赵云")
			.build();
		leftTeam.push_back(temp);
	}
	//创建右边队伍
	{
		CWarriorBuilder builder;
		CHero* temp = builder
			.setAD(30)
			.setBJ(30)
			.setName("马超")
			.build();
		rightTeam.push_back(temp);
	}
}

void CGAME::Run()
{
	while (1) {
		//左边先攻击
		
		int targetIndex = CRandom::getInstance().getRandomIntRange(rightTeam.size(), 0);
		CHero *temp = rightTeam[targetIndex];

		//右边后攻击
	}
}

void CGAME::End()
{
	
}
