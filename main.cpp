#include<iostream>
#include"tool.h"
#include"iostream"
#include "game.h"
int main() {

	//��ʼ�����������
	randomInit();
	CGAME game;
	game.Init();
	game.Run();
	game.End();

	return 0;
}