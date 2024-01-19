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
			.addSkill((CSkill*)(new CWarriorSkillNumber3))
			.addSkill((CSkill*)(new CWarriorSkillNumber4))
			.addSkill((CSkill*)(new CNormalAttack))
			.setName("马超")
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
			.addSkill((CSkill*)(new CWarriorSkillNumber5))
			.addSkill((CSkill*)(new CWarriorSkillNumber6))
			.addSkill((CSkill*)(new CNormalAttack))
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
			.addSkill((CSkill*)(new CWarriorSkillNumber7))
			.addSkill((CSkill*)(new CWarriorSkillNumber8))
			.addSkill((CSkill*)(new CNormalAttack))
			.setName("典韦")
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
			.setName("贾诩")
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
		if (dynamic_cast<CSupporter*>(target)) {//如果是辅助

			auto allIt = (*ourTeam).begin();
			int aliveCount = 1;
			for (;allIt!=(*ourTeam).end();allIt++)
			{
				if ((*allIt)->isAlive()) {
					aliveCount++;
				}
			}
			bool onlySupporter = aliveCount==1;//如果只剩辅助
			if (onlySupporter) {//一把梭哈

				std::cout << target->GetName() << "孤军奋战，他准备发动【毁天灭地】来一把梭哈\n";
				system("pause");

				bool selfDestory = getRandomIntRange(1,0);
				if (selfDestory) {
					std::vector<CHero*>::iterator it = (*enemyTeam).begin();
					for (; it != (*enemyTeam).end(); it++)
					{
						(*it)->dead();
					}
					std::cout << target->GetName() << "梭哈成功！绝地反击\n";
				}
				else {
					(*target).dead();
					std::cout << target->GetName() << "梭哈失败！饮恨而终\n";
				}
			}
			else {//辅助队友
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
				//找到一个没有死亡的敌军
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
				<< "  HP：" << tempHero.getHp()
				<< " | DEF：" << tempHero.getDef();
			auto skills = *(tempHero.getSkills());
			std::vector<CSkill*>::iterator it = skills.begin();
			for (; it != skills.end(); it++)
			{
				std::cout << " " << (*it)->getName() << "CD:" << (*it)->getCCD();
			}
			std::cout << std::endl;
		}
		else {
			std::cout << tempHero.GetName() << "  已经洗白\n";
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
	//创建左边队伍
	createLeftTeam();
	//创建右边队伍
	createRightTeam();
}

void CGAME::Run()
{
	int round = 1;
	bool leftBattle = true;
	std::cout << "=======================游戏开始========================\n";
	std::cout << "=========红方数据==========\n";
	//打印左边战队血量
	displayHero(true);
	std::cout << "=========蓝方数据==========\n";
	//打印右边战队血量
	displayHero(false);
	system("pause");

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

		if (isAllDead(true)) {
			std::cout << "=======================游戏结束，蓝方胜利========================\n";
			break;
		}
		else if (isAllDead(false)) {
			std::cout << "=======================游戏结束，红方胜利========================\n";
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
