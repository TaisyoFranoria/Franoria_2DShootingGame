#pragma once
#include<Dxlib.h>
#include<iostream>
#include<vector>
#include"scene.hpp"
#include"player.hpp"
#include"UI.hpp"
#include"BackGraph.hpp"
#include"shikimi_shot.hpp"
#include"atkup.hpp"
#include"Unknown.hpp"
#include"shikimi_shotEfects.hpp"

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
	std::vector<Unknown_*> enm;
	player* pl;
	shikimi_shot* pl_Bull[300];
	std::vector<player_shotefect*> p_efk;
	int pefk_count;
	int pefk_length;
	int bullet_count;
	ItemBase* Item[50];
	int Itemcount;
	UI_gamescene* UI;
	BackGraph* bg;

	int phase;
	void clear_enemy();
};
