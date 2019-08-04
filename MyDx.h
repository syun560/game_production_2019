#pragma once
#include "DxLib.h"
#define _CRT_SECURE_NO_WARNINGS

class MyDx {
public:
	//色
	static const int WHITE, BLACK, YELLOW, RED, BLUE, GREEN, PURPLE, ORANGE, CYAN, NAVY;
	//画面の大きさ
	static const int FMX, FMY;

	//Dxライブラリのラップ関数
	static int GetRandColor();
	static int SetDrawBrightAll(int Bright);
};