#include "global.h"
#include "MainScene.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	// DXライブラリ初期化
	ChangeWindowMode(TRUE);
	SetGraphMode(FMX, FMY, 32);
	if (DxLib_Init() == -1)	return -1;
	SetDrawScreen(DX_SCREEN_BACK); // 裏画面化

	// 初期化
	MainScene mainScene;

	// メインループ（60FPSなら1秒間に60回実行される）
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		mainScene.update();
		mainScene.draw();
	}

	// DXライブラリ終了処理
	DxLib_End();
	return 0;
}