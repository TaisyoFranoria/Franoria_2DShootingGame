#include"Unknown.hpp"

Unknown::Unknown() {
	x = 0;
	y = 0;
	InitGraph("img/Enemy/Unknown/");
	anim_length = (unsigned)gra.size();
	alive = false;
	shot = false;
}

Unknown::~Unknown() {
	for (int i = 0, n = (unsigned)gra.size(); i < n; i++)DeleteGraph(gra[i]);
}

void Unknown::update() {

}

void Unknown::draw() {

}

void Unknown::spawn(int x, int y) {

}