#pragma once
#include<Dxlib.h>
#include<iostream>
#include"player.hpp"

class scene {
public:
	scene();
	~scene();
	void initialize();
	void finalize();

	void update();
	void draw();
	void update_late();

	float get_time();
	int get_xy(int num);
private:
	player* pl;
	float time;
	int x, y;
};
