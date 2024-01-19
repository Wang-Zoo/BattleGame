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
			.setName("赵云")
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
			.setName("马超")
			.build();
		leftTeam.push_back(temp);
	}
	{
		CSupporterBuilder  sbuilder;
		CHero* temp = sbuilder
			.setHp(2000)
			.setAP(300)
			.setQcd(5)
			.setName("庞统")
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
			.setName("张辽")
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
			.setName("典韦")
			.build();
		rightTeam.push_back(temp);
	}
	{
		CSupporterBuilder sbuilder;
		CHero* temp = sbuilder
			.setHp(2000)
			.setAP(200)
			.setQcd(3)
			.setName("贾诩")
			.build();
		rightTeam.push_back(temp);
	}
}

void CGAME::choose(bool isLeft)
{
	auto& ourTeam = isLeft ? leftTeam : rightTeam;
	forEach(&ourTeam, &leftTeam, &rightTeam, [](CHero* target, auto ourTeam, auto enemyTeam) {
		if (dynamic_cast<CSupporter*>(target)) {//如果是辅助
			bool onlySupporter = (*ourTeam).size() == 1;//如果只剩辅助
			if (onlySupporter) {//一把梭哈
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
			else {//辅助队友
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
			<< "  HP：" << tempHero.getHp()
			<< "|DEF：" << tempHero.getDef()
			<< std::endl;
		return false;
		});

	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

}

void CGAME::Init()
{
	//创建左边队伍
	createLeftTeam();
	//创建右边队伍
	createRightTeam();
}

void CGAME::Run()
{
	int round = 1;
	bool leftBattle = true;
	while (1) {
		std::cout << "=======================第" << round << "回合开始========================\n";
		//左边战队	
		choose(true);
		//右边战队
		choose(false);
		std::cout << "=======================第" << round << "回合结算========================\n";
		//打印左边战队血量
		displayHero(true);
		//打印右边战队血量
		displayHero(false);
		std::cout << "=======================第" << round<< "回合结束========================\n";
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
