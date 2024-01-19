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
	CHero::Action(enemy);
}

