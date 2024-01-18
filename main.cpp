#include<iostream>
#include"random.h"
#include"iostream"
#include "game.h"
int main() {

	//初始化随机数种子
	CRandom::getInstance().Init();

	CGAME game;
	game.Init();
	game.Run();
	game.End();

	return 0;
}