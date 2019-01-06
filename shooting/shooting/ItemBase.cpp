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
		if (pl->get_point(2) < x + 37 && pl->get_point(2) > x - 5 && pl->get_point(3) < y + 37)onColl(pl);
	}
}

void ItemBase::draw() {
	if(alive)DrawGraph(x,y,gra,TRUE);
}

void ItemBase::onColl(player* pl) {
	alive = false;
}