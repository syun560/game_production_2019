#pragma once
#include "MyDx.h"
#include "BaseScene.h"
#include <vector>

struct TwinkleStar {
	int x, y;
	int color;
	bool flag;
};

class SpaceObject {
protected:
	double m;
	double x, y, r, ax, ay, vx, vy, spd, ang;
	double force;
public:
	double getX() const;
	double getY() const;
	double getMass() const;
	double distanceBetweenSpaceObject(double dx, double dy);
	bool isCollided(const SpaceObject&);
};

class BlackHole : public SpaceObject {
public:
	BlackHole();
	void update();
	void draw();
	void resetPosition();
};

class Star : public SpaceObject{
	double imgSize, imgAngle;
	int type;
public:
	Star();
	void attracted(const SpaceObject&);
	bool vanished();
	void update();
	void draw(int* img);
};

class Scene1 : public BaseScene {
	static const int IMG_MAX = 15;
	static const int POWDER_MAX = 100;
	int img[IMG_MAX];
	TwinkleStar powder[POWDER_MAX];
	int bg;
	int gameCnt;
	std::vector<Star> star;
	BlackHole blackHole;
public:
	Scene1();
	~Scene1();
	int Update();
	void Draw();
};