#pragma once
#include<Dxlib.h>
#include"player.hpp"
#include<vector>

class UI_gamescene {
public:
	UI_gamescene(player* pl);
	~UI_gamescene();
	void initialize(player* pl);
	void finalize();
	void updateUI(player* pl);
private:
	int pl_life;
	int pl_lifeMAX;
	int pl_bomb;
	int pl_pow;
	int pl_powMAX;

	std::vector<int> gra;
	void update(player* pl);
	void draw();
	void init_graph();
};