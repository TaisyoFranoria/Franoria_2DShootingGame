#include"scene.hpp"

scene::scene() {
	initialize();
}

scene::~scene() {
	finalize();
}

void scene::initialize() {
	time = 0;
	//あとで変更
	x = 0;
	y = 0;

	pl = new player();
}

void scene::finalize() {
	delete pl;
}

void scene::update() {
	pl->update();
}

void scene::draw() {
	DrawFormatString(0,0,0xFFFFFF,"Running...");
	DrawFormatString(0, 16, 0xFFFFFF, "終了するにはescキーを押してください");
	DrawFormatString(0, 32, 0xFFFFFF, "X:%d Y:%d",pl->get_point(0),pl->get_point(1));
	pl->draw();

}

void scene::update_late() {

}

float scene::get_time() { return time; }

int scene::get_xy(int num) {
	if (num == 0)return x;
	else         return y;
}