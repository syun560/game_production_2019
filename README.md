# game_production_2019
DXライブラリとC/C++を使用して、簡単なゲームを作成しながらプログラミングに慣れていきます。

[新・ゲームプログラミングの館](http://dixq.net/g/)もわかりやすいので、そちらも参考にしてみてください。

## 第1回　～環境構築～
[DXライブラリ置き場　使い方説明](https://dxlib.xsrv.jp/use/dxuse_vscom2019.html)
を参考に、Visual Studio 2019をインストールし、プロジェクトにDXライブラリ用の設定を行います。
(**間違いの指摘が１箇所ありました。4.③の手順ですが、『全般』ではなく『詳細』のようです。**)

最初のプロジェクトの設定は少々面倒ですが、次にプロジェクトを作成するときは、以前のプロジェクトフォルダごとコピーすれば設定せずに済みます。

## 第2回　～ゲームの骨組み～
```
#include "Dxlib.h"

static const int SCREEN_WIDTH = 800;
static const int SCREEN_HEIGHT = 600;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	// DXライブラリ初期化
	ChangeWindowMode(TRUE); // ウィンドウモードで起動
	SetGraphMode(SCREEN_WIDTH , SCREEN_HEIGHT , 32); // 画面サイズを指定
	if (DxLib_Init() == -1)	return -1; // DXライブラリの初期化
	SetDrawScreen(DX_SCREEN_BACK); // 裏画面化

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
		if (x > SCREEN_WIDTH) x = 0;
		y += spd;
		if (y > SCREEN_HIGHT) y = 0;
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

以上が基本的なプログラムの骨格になります。

**初期化（DXライブラリ）→初期化（変数宣言、画像、音楽の読み込み）→メインループ→終了処理**

というのが大きなプログラムの流れです。

while文の中の処理を**メインループ**と呼び、60分の1秒ごと（環境によって異なる）に実行されるゲームの主な処理を書いていきます。

さらに、メインループでは、**入力フェーズ**→**計算フェーズ**→**描画フェーズ**の3つのフェーズに処理をわけると流れがわかりやすくなります。

## 第3回 ～DXライブラリの様々な関数～

DXライブラリで使用できる主な関数は、[DXライブラリ　関数リファレンスページ](https://dxlib.xsrv.jp/dxfunc.html)に、使用例とともに記載されています。（リファレンスにはない隠し関数というものもあり、`DxLib.h`に記述されています）

よく使う関数について、以下に説明します。

#### 入力系
### GetHitStateKeyAll
第二回の例にあるように、char型のサイズ256の配列に、すべてのキーの押下状態を格納します。`CheckHitKey`を何度も使用するより効率が良いらしいので、できればこちらを使いましょう。

### GetMousePoint
マウスカーソルのX座標とY座標を取得します。このように、２つ以上の値を返す関数は、**ポインタ**を使うことが多いです。

#### 計算系
### GetRand
乱数を生成します。ゲームでは非常によく使う関数だと思います。

### GetColor
R, G, Bで色を指定します。頻繁に使う色は`const int WHITE = GetColor(255, 255, 255);`のように、定数に入れておくと便利です。

#### 描画系

### DrawLine, DrawBox, DrawCircle
線、四角形、丸を描きます。画像がまだ用意できていない時などにも役立ちます。

### DrawFormatString
画面に情報を表示するのに使います。現在の変数の中身がどうなっているか確認したい場合など、デバッグ時にも使えます。

### DrawGraph, DrawRotaGraph
`LoadGraph`関数を使用して（LoadGraphを使うのは最初だけ）メモリに読みこんでおいた画像を表示します。

#### サウンド関連
### PlayMusic
音楽ファイルの読み込みと再生を同時に行ってくれます。**BGM**などに使うと良いでしょう。

### PlaySoundMem
`DrawGraph`関数などと同様に、`LoadSoundMem`であらかじめメモリに読み込んだ音を表示します。**効果音**など何度も再生が必要な音に使います。

## 第4回 ～見やすいコードを書く～
他人に見せないものでも、コードの量が増えてくるにつれ、自分でも読めなくなったり、バグを追いづらくなったりするので、見やすいコードを書くことは大切です。

### わかりやすい変数名
変数名が少々長くなっても、わかりやすい変数名にすることが大切です。（エディターに補間機能もあるので）

### ファイルの分割
「プロジェクト」→「新しい項目の追加」から、ソースファイルやヘッダファイルを追加することができます。

ファイルを分割することにより、コンパイルが変更したファイルごとに行われ、コンパイル時間の短縮につながるので、機能ごとに分割していきましょう。

### オブジェクト指向
C++では、`class`を使用するとにより、関連する変数、関数を一体として扱うことができます。
