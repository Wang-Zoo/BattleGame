#include "supporter.h"
#include <iostream>
#include "random.h"
#include "windows.h"
CSupporter::CSupporter()
{
}
void CSupporter::Run() {
	CHero::Run();
}

void CSupporter::Action(CHero* enemy)
{
	if (enemy->getTeamNum() == teamNum) {
		CHero::Action(enemy);
	}
	else {
		//È°½µ¼¼ÄÜ
		for (const auto& temp:skills)
		{
			CSkillSpy*  tempSkill= dynamic_cast<CSkillSpy*>(temp);
			if (tempSkill) {
				temp->Action(this,enemy);
				break;
			}
		}
	}
}

