# game_production_2019
DXライブラリとC++を使用して簡単なゲームを作りながらプログラミングに慣れていきます。

## 第1回　～環境構築～
[https://dxlib.xsrv.jp/use/dxuse_vscom2019.html](https://dxlib.xsrv.jp/use/dxuse_vscom2019.html)
を参考に、Visual Studio 2019をインストールし、DXライブラリの設定を行います。

## 第2回　～ゲームの骨組み～
```
#include "Dxlib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	// DXライブラリ初期化
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1)	return -1;
	SetDrawScreen(DX_SCREEN_BACK);

	// 変数宣言、初期化
	int x = 0;
	int y = 0;
	int r = 50;
	int spd = 12;

	// メインループ（60FPSなら1秒間に60回実行される）
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		// 入力
		char keyState[256];
		GetHitKeyStateAll(keyState);
		
		// 計算
		x += spd;
		if (x > 740) x = 0;
		y += spd;
		if (y > 580) y = 0;
		if (keyState[KEY_INPUT_ESCAPE] == 1) break;

		// 描画
		DrawCircle(x, y, r, GetColor(122, 255, 255));
		DrawFormatString(0, 0, GetColor(255, 255, 255), "x = %d, y = %d", x, y);
	}

	// DXライブラリ終了処理
	DxLib_End();
	return 0;
}
```

## 第2回