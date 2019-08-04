#pragma once
#include "MyDx.h"

class Input{
	static int key[256];
	static char keyBuf[256];
	static int mouseX, mouseY, mouseL, mouseR, mouseM;
public:
	static void Mouse(int*,int*);
	static int MouseL();
	static int MouseR();
	static int MouseM();
	static int Key(int);
	static void Update();
	static void Draw();
};