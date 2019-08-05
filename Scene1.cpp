#include "Scene1.h"
#include "DxLib.h"
#include "Input.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>

double SpaceObject::getX() const{ return x; }
double SpaceObject::getY() const{ return y; }
double SpaceObject::getMass() const { return m; }

double SpaceObject::distanceBetweenSpaceObject(double dx, double dy) {
	//return sqrt((mx - obj.getX()) * (mx - obj.getX()) + (my - obj.getY()) * (my - obj.getY()));
	return sqrt((x - dx) * (x - dx) + (y - dy) * (y - dy));
}

bool SpaceObject::isCollided(const SpaceObject& obj) {
	if ((x - obj.x) * (x - obj.x) + (y - obj.y) * (y - obj.y) < (obj.r + r) * (obj.r + r)) return true;
	else return false;
}

Star::Star() {
	ax = ay = vx = vy = sx = sy = 0.0;
	vx = -2.0 + GetRand(400) / 100.0;
	vy = -2.0 + GetRand(400) / 100.0;
	x = (double)(MyDx::FMX / 2 - 50 + GetRand(100));
	y = (double)(MyDx::FMY / 2 - 50 + GetRand(100));
	double size = 0.8 + GetRand(100)/100.0;
	r = 10.0 * size;
	m = 1.0 * size;
	type = GetRand(8);
	if (GetRand(20) == 1) type = 9;
	else if (GetRand(30) == 1) type = 10;
	imgSize = 0.08 * size;
	imgAngle = DX_PI * GetRand(100000);
	if (type == 9) imgAngle = 0;
	flag = false;
}

void Star::attracted(const SpaceObject& obj) {
	double dist = distanceBetweenSpaceObject(obj.getX(), obj.getY());
	double angle = atan2(obj.getY() - y, obj.getX() - x);
	static const double G = 50.0;
	double F = G * m * obj.getMass() / dist / dist;
	ax = F * cos(angle) / m;
	ay = F * sin(angle) / m;
}

void Star::update() {
	int mx, my;
	Input::Mouse(&mx, &my);
	if (flag) {
		x = sx + mx;
		y = sy + my;
	}
	else {
		vx += ax;
		vy += ay;
		x += vx;
		y += vy;
	}
}

bool Star::vanished() {
	static double const margin = 100.0;
	if (x < -margin || y < -margin || x > MyDx::FMX + margin || y > MyDx::FMY + margin) return true;
	return false;
}

void Star::stick(double dx, double dy) {
	ax = ay = vx = vy = 0.0;
	sx = x - dx;
	sy = y - dy;
	flag = true;
}

bool Star::isSticked() {
	return flag;
}

void Star::draw(int* img) {
	float fx = (float)x;
	float fy = (float)y;
	DrawRotaGraphF(fx, fy, imgSize, imgAngle, img[type], TRUE);
	//DrawCircle(intX, intY, (int)r, MyDx::RED, FALSE);
	//DrawFormatString(intX, intY, MyDx::YELLOW, "(%d,%d)", intX, intY);
	//DrawLine(intX, intY, intX + (int)(ax * 1000.0), intY + (int)(ay * 1000.0), MyDx::RED, 2);
}

BlackHole::BlackHole() {
	m = 20.0;
	r = 20.0;
	ax = ay = 0.0;
	vx = 1.0;
	vy = 1.0;
	x = 20.0;
	y = 20.0;
	spd = 2.0;
	ang = 0.0;
	force = 1.0;
}

void BlackHole::inflate() {
	r *= 1.03;
	m *= 1.03;
}

void BlackHole::update() {
	int mx, my;
	Input::Mouse(&mx, &my);
	x = mx;
	y = my;
}

void BlackHole::draw() {
	DrawCircle((int)x, (int)y, (int)(r * 1.2), GetColor(100, 100, 100), TRUE);
	DrawCircle((int)x, (int)y, (int)r, MyDx::BLACK, TRUE);
	//DrawCircle((int)x, (int)y, (int)r, MyDx::RED, FALSE);
	//DrawFormatString((int)x, (int)y, MyDx::YELLOW, "(%d,%d)", (int)x, (int)y);
}

Scene1::Scene1(int dlevel) {
	// ÉçÅ[Éh
	bg = LoadGraph("dat/img/bg_uchu_space.jpg");
	img[0] = LoadGraph("dat/img/small_star1_blue.png");
	img[1] = LoadGraph("dat/img/small_star2_skyblue.png");
	img[2] = LoadGraph("dat/img/small_star3_brown.png");
	img[3] = LoadGraph("dat/img/small_star4_pink.png");
	img[4] = LoadGraph("dat/img/small_star5_purple.png");
	img[5] = LoadGraph("dat/img/small_star6_orange.png");
	img[6] = LoadGraph("dat/img/small_star7_yellow.png");
	img[7] = LoadGraph("dat/img/small_star8_red.png");
	img[8] = LoadGraph("dat/img/small_star9_green.png");
	img[9] = LoadGraph("dat/img/landmark_goryoukaku.png");
	img[10] = LoadGraph("dat/img/alien_ufo.png");
	gameCnt = 0;
	level = dlevel;
	stickedNum = 0;
	int ballNum = level * 2;
	goal =  ballNum / 2;
	for (int i = 0; i < ballNum; ++i) star.emplace_back();
	for (int i = 0; i < POWDER_MAX; ++i) {
		powder[i].x = GetRand(MyDx::FMX);
		powder[i].y = GetRand(MyDx::FMY);
	}
	PlayMusic("dat/music/uchuyuei.mp3", DX_PLAYTYPE_LOOP);
}

Scene1::~Scene1() {
	InitGraph();
	StopMusic();
}

int Scene1::Update() {
	if (star.size() - stickedNum < goal) {
		BaseScene::Miss();
	}
	gameCnt++;
	if (gameCnt == 1000) gameCnt = 500;
	else if (gameCnt == 1128) {
		return -1;
	}
	if (gameCnt < 255) {
		SetVolumeMusic(gameCnt);
	}
	else if (gameCnt > 1000) {
		SetVolumeMusic((1128 - gameCnt) * 2);
		if (Input::Key(KEY_INPUT_ESCAPE) == 1) return -1;
	}
	if(BaseScene::Update() == -4) return ++level;

	if (Input::Key(KEY_INPUT_ESCAPE) == 1 && gameCnt < 1000) {
		gameCnt = 1000;
	}
	if (Input::Key(KEY_INPUT_R) == 1) return level;
	if (Input::Key(KEY_INPUT_M) == 1) star.emplace_back();
	blackHole.update();

	auto itr = star.begin();
	while (itr != star.end()) {
		if (!itr->isSticked() && gameCnt > 60)
			itr->attracted(blackHole);
		itr->update();
		if (!itr->isSticked() && itr->isCollided(blackHole) && gameCnt > 60) {
			itr->stick(blackHole.getX(), blackHole.getY());
			blackHole.inflate();
			stickedNum++;
			itr++;
		}
		else if (itr->vanished()) {
			itr = star.erase(itr);
		}
		else itr++;
	}
	return 0;
}

void Scene1::Draw(){
	// îwåi
	//DrawRotaGraph(MyDx::FMX / 2, MyDx::FMY / 2, 2.0, 0.0, bg, TRUE);
	if (gameCnt < 128) {
		MyDx::SetDrawBrightAll(gameCnt * 2);
	}
	else if (gameCnt > 1000) {
		MyDx::SetDrawBrightAll((1128 - gameCnt) * 2);
	}
	DrawBox(0, 0, MyDx::FMX, MyDx::FMY, GetColor(2, 2, 22), TRUE);
	for (int i = 0; i < POWDER_MAX; ++i) {
		DrawPixel(powder[i].x, powder[i].y, MyDx::GetRandColor());
	}

	SetDrawMode(DX_DRAWMODE_BILINEAR);
	for (auto itr = star.begin(); itr != star.end(); ++itr) {
		itr->draw(img);
	}
	SetDrawMode(DX_DRAWMODE_NEAREST);
	blackHole.draw();

	BaseScene::Draw();

	DrawFormatString(0,MyDx::FMY - 20, MyDx::WHITE, "Level: %d, %d/%d", level, goal, star.size() - stickedNum);
}