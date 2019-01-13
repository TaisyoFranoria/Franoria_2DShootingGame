#pragma once
#include<Dxlib.h>
#include<iostream>

class scene {
public:
	scene();
	~scene();
	virtual void initialize();
	virtual void finalize();

	virtual void update();
	virtual void draw();
	virtual void update_late();
	virtual void update_ALT();

	bool get_alive();
	bool pose_now;
protected:
	int time;
	int x, y;
	bool alive;
};
