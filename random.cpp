#include "random.h"
#include <iostream>
void CRandom::Init()
{
	srand(time(0));
}

int CRandom::getRandomInt()
{
	return rand();
}

int CRandom::getRandomIntRange(int max, int min)
{
	if (min > max) {
		min = min ^ max;
		max = min ^ max;
		min = min ^ max;
	}
	return rand() % (max - min + 1)+ min;
}


