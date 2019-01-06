#include"ItemBase.hpp"

ItemBase::ItemBase() {
	x, y, gra = 0;
	pl_up = false;
	alive = false;
}

ItemBase::~ItemBase(){
	DeleteGraph(gra);
}

void ItemBase::spawn(int x,int y) {
	this->x = x;
	this->y = y;
	alive = true;
}

void ItemBase::update(player* pl) {
	if (alive) {
		y++;
		if (pl->get_point(3) < 200)pl_up = true;
		if (pl_up) {
			if (y >= pl->get_point(3))y -= 20;
			if (y <= pl->get_point(3))y += 20;
			if (x >= pl->get_point(2))x -= 20;
			if (x <= pl->get_point(2))x += 20;
		}
		if (pl->get_point(2) < x + 47 && pl->get_point(2) > x - 15 && pl->get_point(3) < y + 47)onColl(pl);
		if (y > 800 || x > 800 || x < 0)alive = false;
	}
}

void ItemBase::draw() {
	if(alive)DrawGraph(x,y,gra,TRUE);
}

void ItemBase::onColl(player* pl) {
	alive = false;
	pl_up = false;
}