#include "warrior.h"
#include "output.h"
#include <iostream>
#include "tool.h"
#include "windows.h"

CWarrior::CWarrior()
{
	mAttribute.bjValue = 50;
}

void CWarrior::Run() {
	CHero::Run();
}

void CWarrior::Action(CHero* enemy)
{
	CHero::Action(enemy);
}