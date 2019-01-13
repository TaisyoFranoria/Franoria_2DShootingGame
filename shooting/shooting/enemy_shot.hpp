#pragma once
#include"shot.hpp"
#include"player.hpp"

class enemy_shot : public shot {
public:
	enemy_shot();
	~enemy_shot();
	void update();
	void draw();
	void enemy_coll(player* pl);
};