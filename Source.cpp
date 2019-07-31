#include "global.h"
#include "MainScene.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	// DX���C�u����������
	ChangeWindowMode(TRUE);
	SetGraphMode(FMX, FMY, 32);
	if (DxLib_Init() == -1)	return -1;
	SetDrawScreen(DX_SCREEN_BACK); // ����ʉ�

	// ������
	MainScene mainScene;

	// ���C�����[�v�i60FPS�Ȃ�1�b�Ԃ�60����s�����j
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		mainScene.update();
		mainScene.draw();
	}

	// DX���C�u�����I������
	DxLib_End();
	return 0;
}