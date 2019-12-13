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
	void inflate();
};

class Star : public SpaceObject{
	double imgSize, imgAngle;
	double sx, sy;
	bool flag;
	int type;
public:
	Star();
	void attracted(const SpaceObject&);
	bool vanished();
	void stick(double dx, double dy);
	void update();
	void draw(int* img);

	bool isSticked();
};

class Scene1 : public BaseScene {
	static const int IMG_MAX = 15;
	static const int POWDER_MAX = 300;
	int img[IMG_MAX];
	int se;
	TwinkleStar powder[POWDER_MAX];
	int bg;
	int gameCnt;
	int stickedNum, level, goal;
	std::vector<Star> star;
	BlackHole blackHole;
public:
	Scene1(int dlevel);
	~Scene1();
	int Update();
	void Draw();
};