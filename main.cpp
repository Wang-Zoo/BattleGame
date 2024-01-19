#include<iostream>
#include"tool.h"
#include"iostream"
#include "game.h"
int main() {

	//初始化随机数种子
	randomInit();
	CGAME game;
	game.Init();
	game.Run();
	game.End();

	return 0;
}