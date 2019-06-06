#include "Dxlib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	// DX���C�u����������
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1)	return -1;
	SetDrawScreen(DX_SCREEN_BACK);

	// �ϐ��錾�A������
	int x = 0;
	int y = 0;
	int r = 50;
	int spd = 4;

	// ���C�����[�v�i60FPS�Ȃ�1�b�Ԃ�60����s�����j
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		// ����
		char keyState[256];
		GetHitKeyStateAll(keyState);

		// �v�Z
		x += spd;
		if (x > 740) x = 0;
		y += spd;
		if (y > 580) y = 0;
		if (keyState[KEY_INPUT_ESCAPE] == 1) break;

		// �`��
		DrawCircle(x, y, r, GetColor(122, 255, 255));
		DrawFormatString(0, 0, GetColor(255, 255, 255), "x = %d, y = %d", x, y);
	}

	// DX���C�u�����I������
	DxLib_End();
	return 0;
}