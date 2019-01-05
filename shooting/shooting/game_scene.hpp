#pragma once
#include<Dxlib.h>
#include<iostream>
#include"scene.hpp"
#include"player.hpp"
#include"UI.hpp"

#define GAME_WIDTH (850)
#define GAME_WIDTH (710)

class GameScene:public scene {
public:
	GameScene();
	virtual ~GameScene();
	virtual void initialize();
	virtual void finalize();

	virtual void update();
	virtual void draw();
	virtual void update_late();

	float get_time();
	int get_xy(int num);
protected:
	player* pl;
	UI_gamescene* UI;
};
