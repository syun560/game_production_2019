#pragma once
#include "DxLib.h"
#define _CRT_SECURE_NO_WARNINGS

class MyDx {
public:
	//�F
	static const int WHITE, BLACK, YELLOW, RED, BLUE, GREEN, PURPLE, ORANGE, CYAN, NAVY;
	//��ʂ̑傫��
	static const int FMX, FMY;

	//Dx���C�u�����̃��b�v�֐�
	static int GetRandColor();
	static int SetDrawBrightAll(int Bright);
};