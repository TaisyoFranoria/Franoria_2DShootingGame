#pragma once
#include<Dxlib.h>

class BackGraph{
public:
	BackGraph();
	~BackGraph();
	void PlayGraph();
private:
	void update();
	void draw();
	int gra;
	int x, y;
	int timecount;
};
