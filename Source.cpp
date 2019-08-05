#include "Input.h"
#include "Game.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	SetMainWindowText("Save the stars");
	SetGraphMode(MyDx::FMX, MyDx::FMY, 32);
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1)	return -1;
	SetDrawScreen(DX_SCREEN_BACK);

	Game game;
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		Input::Update();
		
		if(game.Update() == -1) break;
		game.Draw();

	}
	DxLib_End();
	return 0;
}
