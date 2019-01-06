#pragma once
#include<Dxlib.h>
#include<iostream>
#include"scene.hpp"
#include"player.hpp"
#include"UI.hpp"
#include"BackGraph.hpp"
#include"shikimi_shot.hpp"
#include"atkup.hpp"

#define GAME_WIDTH (850)
#define GAME_HIGHT (710)

class GameScene:public scene {
public:
	GameScene();
	virtual ~GameScene();
	virtual void initialize();
	virtual void finalize();

	virtual void update();
	void update_abs();
	virtual void draw();
	void draw_abs();
	virtual void update_late();

	void shot_emit(int x,int y,int pw,bool slow);

	int get_time();
	int get_xy(int num);
protected:
	player* pl;
	shikimi_shot* pl_Bull[300];
	int bullet_count;
	ItemBase* Item[50];
	int Itemcount;
	UI_gamescene* UI;
	BackGraph* bg;
};
