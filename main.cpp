#include<iostream>
#include"tool.h"
#include"iostream"
#include "game.h"
#include"Windows.h"
int main() {


	//��ʼ�����������
	randomInit();
	//��Ϸ��ʼ
	CGAME game;
	game.Init();
	game.Run();
	game.End();

	return 0;
}