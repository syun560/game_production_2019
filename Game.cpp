#include "Game.h"

Game::Game() {
	scene = MAIN;
	gameScene = new Scene1(1);
}

Game::~Game() {
	delete gameScene;
}

int Game::Update() {
	static int t = 1;
	switch (scene) {
	case TITLE:
		t = title.Update();
		if (t == -1) return -1;
		else if (t == 0) return 0;
		else {
			scene = MAIN;
			gameScene = new Scene1(1);
		}
		break;
	case MAIN:
		int g = gameScene->Update();
		if (g == -1) {
			delete gameScene;
			scene = TITLE;
		}
		else if (g == -2) {
			delete gameScene;
			scene = MAIN;
			gameScene = new Scene1(t);
		}
		else if (g == -3) {
			return -1;
		}
		else if (g > 0) {
			delete gameScene;
			scene = MAIN;
			gameScene = new Scene1(g);
		}
		break;
	}
	return 0;
}

void Game::Draw() {
	switch (scene) {
	case TITLE:
		title.Draw();
		break;
	case MAIN:
		gameScene->Draw();
		break;
	}
}