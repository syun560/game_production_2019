#pragma once
#include "MyDx.h"

class BaseScene {
	enum State {
		PLAYING,
		PAUSE,
		CLEARED,
		MISS,
	};
	int time;
	State state;
	int font;
public:
	BaseScene();
	virtual ~BaseScene();
	void Miss();
	void Clear();
	virtual int Update();
	virtual void Draw();
};