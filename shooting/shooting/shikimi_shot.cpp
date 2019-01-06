#include"shikimi_shot.hpp"

shikimi_shot::shikimi_shot() {
	x = 0;
	y = 0;
	alive = false;
	gra = LoadGraph("img/shot/shikimi_shot01.png");
}

shikimi_shot::~shikimi_shot() {
	DeleteGraph(gra);
}

void shikimi_shot::update() {
	if (alive) { y-=20; }
	if (y <= -20)alive = false;
}

void shikimi_shot::onColl() {
	alive = false;
}