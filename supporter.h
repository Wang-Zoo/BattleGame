#pragma once
#include"hero.h"
//սʿӢ��
class CSupporter : public CHero {
private:
	CSupporter();
	friend class CSupporterBuilder;
public:
	void Run();
	void Action(CHero* tag);

};