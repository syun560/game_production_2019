#include "BaseScene.h"
#include "Input.h"

BaseScene::BaseScene() {
	time = 60 * 7; // 60FPSの場合7秒
	state = PLAYING;
	font = CreateFontToHandle(NULL, 40, 3);
}

BaseScene::~BaseScene() {
	DeleteFontToHandle(font);
}

int BaseScene::Update() {
	if (state == PLAYING) time--;
	if (time == 0) {
		state = CLEARED;
	}
	if (state == CLEARED && Input::Key(KEY_INPUT_RETURN) == 1) {
		return -4;
	}
	return 0;
}

void BaseScene::Miss() {
	if (state == PLAYING) {
		state = MISS;
	}
}

void BaseScene::Clear() {
	state = CLEARED;
}

void BaseScene::Draw() {
	// カウントダウン
	int second = time / 60;
	if(second > 3) DrawFormatStringToHandle(0, 0, MyDx::WHITE, font, "%d", second);
	else DrawFormatStringToHandle(0, 0, MyDx::RED, font, "%d", second);
	if (state != PLAYING) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 32);
		DrawBox(50,50,MyDx::FMX-50,MyDx::FMY-50,MyDx::WHITE,TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		if(state == CLEARED) DrawFormatString(100, 200, MyDx::GREEN, "Cleared");
		else if(state == MISS) DrawFormatString(100, 200, MyDx::RED, "MISS");
		if (state == CLEARED) DrawFormatString(100, 320, MyDx::WHITE, "Press Enter to next level");
		else if(state == MISS) DrawFormatString(100, 320, MyDx::WHITE, "Press R to retry");
		DrawFormatString(100, 340, MyDx::WHITE, "Press ESC to title");
	}
}