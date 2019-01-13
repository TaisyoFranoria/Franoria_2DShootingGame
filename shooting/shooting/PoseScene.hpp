#pragma once
#include"scene.hpp"

class PoseScene : public scene {
public:
	PoseScene();
	~PoseScene();
	void update();
	void draw();
private:
	int state;
	int gra[2];
};
