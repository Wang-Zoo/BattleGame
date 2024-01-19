#pragma once
#include"hero.h"
//Õ½Ê¿Ó¢ÐÛ
class CSupporter : public CHero {
private:
	CSupporter();
	friend class CSupporterBuilder;
public:
	void Run();
	void Action(CHero* tag);

};