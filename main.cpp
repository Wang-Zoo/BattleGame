#include<iostream>
#include"tool.h"
#include"iostream"
#include "game.h"
#include"Windows.h"
int main() {


	//初始化随机数种子
	randomInit();
	//游戏开始
	CGAME game;
	game.Init();
	game.Run();
	game.End();

	return 0;
}