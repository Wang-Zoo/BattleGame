#include "hero.h"

SAttribute* CHero::GetAttribute()
{
	return &mAttribute;
}

int CHero::getState()
{
	return mState;
}

void CHero::setState(int state)
{
	mState = state;
}
