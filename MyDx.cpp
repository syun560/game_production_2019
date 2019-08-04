#include "MyDx.h"

const int MyDx::FMX = 800;
const int MyDx::FMY = 600;
const int MyDx::WHITE = GetColor(255, 255, 255);
const int MyDx::BLACK = GetColor(0, 0, 0);
const int MyDx::YELLOW = GetColor(255, 255, 0);
const int MyDx::RED = GetColor(255, 0, 0);
const int MyDx::BLUE = GetColor(0, 0, 255);
const int MyDx::GREEN = GetColor(0, 255, 0);
const int MyDx::PURPLE = GetColor(255, 0, 255);
const int MyDx::ORANGE = GetColor(255, 69, 0);
const int MyDx::CYAN = GetColor(255, 255, 0);
const int MyDx::NAVY = GetColor(122, 122, 122);

int MyDx::GetRandColor() {
	return GetColor(GetRand(255), GetRand(255), GetRand(255));
}
int MyDx::SetDrawBrightAll(int Bright) {
	return SetDrawBright(Bright, Bright, Bright);
}