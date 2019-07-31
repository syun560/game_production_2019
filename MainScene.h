#pragma once
#include "global.h"

struct Ball {
	int x, y, r;
};

class MainScene {
	Ball ball[50];
public:
	MainScene();
	void update();
	void draw();
};