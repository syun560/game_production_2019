#include "Title.h"
#include "Input.h"

Title::Title() {
	
}

int Title::Update() {
	if (Input::Key(KEY_INPUT_ESCAPE) == 1) return -1;
	if (Input::MouseL() == 1) return 1;
	return 0;
}

void Title::Draw() {
	MyDx::SetDrawBrightAll(255);
	static const int LIST_X = 80;
	static const int LIST_Y = 100;
	DrawFormatString(30, 40, MyDx::WHITE, "Game");
	DrawFormatString(LIST_X, LIST_Y, MyDx::WHITE, "Start");
	// DrawBox(LIST_X, LIST_Y + selectmode * 20, LIST_X + LIST_WIDTH, LIST_Y + (selectmode + 1) * 20, MyDx::YELLOW, FALSE);
	// DrawFormatString(1, 1, MyDx::WHITE, "mode = %d, game = %d", selectmode, selectgame);
}