# game_production_2019
DXライブラリとC++を使用して、簡単なゲームを作成しながらプログラミングに慣れていきます。

## はじめに
4回に分けて説明していきます。
その前に、C/C++の文法的なことについて知る必要があります。
具体的には、

### なぜDXライブラリなの？
ゲームを制作する手段としては、
他にも、UnityやUnreal Engineなどのゲームエンジンがあります。
僕が一番慣れ親しんだものしか、教えられないからです。
でも、正直初心者に教えるのはどうかと思っています。
でも正直、ちょっと後悔しています。

ここから、

ゲーム制作は大変ということを知るのは大事だと思っています。
できることと、できないことを知る必要があります。

### C/C++ってなんぞ
型がある、ということは結構便利だなあ

### 目的
目標としましょう。

## 第1回　～環境構築～
[https://dxlib.xsrv.jp/use/dxuse_vscom2019.html](https://dxlib.xsrv.jp/use/dxuse_vscom2019.html)
を参考に、Visual Studio 2019をインストールし、プロジェクトにDXライブラリ用の設定を行います。

……なかなか大変な作業です。

最後の段の、画面中央に、ドットを描画する関数が表示されたら、完成です。
解像度の高いパソコンだと、画面のゴミかな？　って感じ
（なんでこんなに分かりづらいサンプルコードなんだろう？？？）

## 第2回　～ゲームの骨組みの完成～
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

長い！

### コードの説明
#### メインループ
入力、計算と、描画、が基本やで！！！
60FPSで、Unityで言うところの、Update関数！

#### ゲームの書き出しについて

## 第3回 ～DXライブラリの様々な関数～


### 関数ってなんや
覚える必要はないです。都度リファレンスを確認しに行くのがよいでしょう。

#### 描画系

#### DrawFormatString()
デバッグ情報などを画面に表示するのに使います。実際、ゲームで使用する時は、フォントを変えて見たほうがいいかも。

#### DrawGraph()
画面に読みこんだ画像を表示するんやで。


基本的に使わない、と考えてください。

### 見やすいコードの書き方（設計）
見やすければ良いでしょうか？

### C++流の書き方
オブジェクト指向でしゅう。

## 第4回 ～見やすいコードの書き方～
見やすくする必要があります。途中でわけがわからなくなってきます。