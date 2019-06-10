#include "Dxlib.h"

struct Ball {
	int x, y, r, spd;
	double vx, vy;
};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	// DX���C�u����������
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1)	return -1;
	SetDrawScreen(DX_SCREEN_BACK); // ����ʉ�

	// �ϐ��錾�A������
	Ball ball[50];
	for (int i = 0; i < 50; i++) {
		ball[i].x = GetRand(680);
		ball[i].y = GetRand(400);
		ball[i].vx = -3 + GetRand(5);
		ball[i].vy = 4 + GetRand(2);
		ball[i].spd = 3;
		ball[i].r = 10;
	}
	int x = 0;
	int y = 0;
	int r = 50;
	int spd = 5;

	// ���C�����[�v�i60FPS�Ȃ�1�b�Ԃ�60����s�����j
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		// ����
		char keyState[256];
		GetHitKeyStateAll(keyState);


		// �v�Z
		if (keyState[KEY_INPUT_RIGHT] == 1) x += spd;
		if (keyState[KEY_INPUT_LEFT] == 1) x -= spd;
		if (keyState[KEY_INPUT_UP] == 1) y -= spd;
		if (keyState[KEY_INPUT_DOWN] == 1) y += spd;

		for (int i = 0; i < 50; i++) {
			ball[i].vy += 0.1;
			ball[i].x += (int)ball[i].vx;
			ball[i].y += (int)ball[i].vy;
			if (ball[i].x > 600) ball[i].vx *= -1.0;
			if (ball[i].x < 0) ball[i].vx *= -1.0;
			if (ball[i].y > 480) ball[i].vy *= -1;
		}

		if (keyState[KEY_INPUT_ESCAPE] == 1) break;

		// �`��
		DrawCircle(x, y, r, GetColor(122, 255, 255));
		for (int i = 0; i < 50; i++) {
			DrawCircle(ball[i].x, ball[i].y, ball[i].r, GetColor(255, 15, 255));
		}

		DrawFormatString(0, 0, GetColor(255, 255, 255), "x = %d, y = %d", x, y);
	}

	// DX���C�u�����I������
	DxLib_End();
	return 0;
}