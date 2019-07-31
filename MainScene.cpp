#include "MainScene.h"

MainScene::MainScene() {
	for (int i = 0; i < 50; i++) {
		ball[i].x = GetRand(FMX);
		ball[i].y = GetRand(FMY);
		ball[i].r = 12;
	}
}

void MainScene::update() {
	char keyState[256];
	GetHitKeyStateAll(keyState);
	for (int i = 0; i < 50; i++) {
		ball[i].x += -2 + GetRand(4);
		ball[i].y += -2 + GetRand(4);
	}
}

void MainScene::draw() {
	for (int i = 0; i < 50; i++) {
		DrawCircle(ball[i].x, ball[i].y, ball[i].r, WHITE);
	}
}