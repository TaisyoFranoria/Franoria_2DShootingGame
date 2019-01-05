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

	
}

void scene::finalize() {
	
}

void scene::update() {
	
}

void scene::draw() {
	DrawFormatString(0,0,0xFFFFFF,"Running...");
	DrawFormatString(0, 16, 0xFFFFFF, "終了するにはescキーを押してください");
}

void scene::update_late() {

}

