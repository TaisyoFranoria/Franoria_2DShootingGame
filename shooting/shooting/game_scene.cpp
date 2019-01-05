#include"game_scene.hpp"

GameScene::GameScene() {
	initialize();
}

GameScene::~GameScene() {
	finalize();
}

void GameScene::initialize() {
	time = 0;
	//‚ ‚Æ‚Å•ÏX
	x = 0;
	y = 0;

	pl = new player();
	UI = new UI_gamescene(pl);
}

void GameScene::finalize() {
	delete pl;
}

void GameScene::update() {
	UI->updateUI(pl);
	pl->update();
}

void GameScene::draw() {
	pl->draw();

}

void GameScene::update_late() {
	pl->update_late();
	if (pl->get_status(0) <= 0) alive = false;
}

float GameScene::get_time() { return time; }

int GameScene::get_xy(int num) {
	if (num == 0)return x;
	else         return y;
}