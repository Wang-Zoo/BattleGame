#include"tool.h"
#include"iostream"
CHero* forEach(std::vector<CHero*>* origins, HeroCallback callback)
{
	std::vector<CHero*>::iterator it = (*origins).begin();

	for (; it != (*origins).end(); it++)
	{
		if (callback(*it))
			return (*it);
	}
	return nullptr;
}

void forEach(std::vector<CHero*>* origins, std::vector<CHero*>* leftTeam,std::vector<CHero*>* rightTeam,  HeroCallbackAll callback)
{
	std::vector<CHero*>::iterator it = (*origins).begin();

	for (; it != (*origins).end(); it++)
	{
		callback(*it, origins == leftTeam ? leftTeam : rightTeam, origins == leftTeam ? rightTeam : leftTeam);
	}
}

void randomInit()
{
	srand(time(0));
}

int getRandomInt()
{
	return rand();
}

int getRandomIntRange(int max, int min)
{
	if (min > max) {
		min = min ^ max;
		max = min ^ max;
		min = min ^ max;
	}
	return rand() % (max - min + 1) + min;
}

bool getPercent(int target) {
	return getRandomIntRange(9, 0)<=target;
}

