#include<iostream>
#include"random.h"
#include"iostream"
#include "game.h"
int main() {

	//��ʼ�����������
	CRandom::getInstance().Init();

	CGAME game;
	game.Init();
	game.Run();
	game.End();

	return 0;
}