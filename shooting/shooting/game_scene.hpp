#pragma once
#include<Dxlib.h>
#include<iostream>
#include"scene.hpp"
#include"player.hpp"
#include"UI.hpp"

class GameScene:public scene {
public:
	GameScene();
	~GameScene();
	void initialize();
	void finalize();

	void update();
	void draw();
	void update_late();

	float get_time();
	int get_xy(int num);
private:
	player* pl;
	UI_gamescene* UI;
};
