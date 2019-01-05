#include"game_scene.hpp"

GameScene::GameScene() {
	initialize();
}

GameScene::~GameScene() {
	finalize();
}

void GameScene::initialize() {
	time = 0;
	//あとで変更
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
	DrawFormatString(0, 0, 0xFFFFFF, "Running...");
	DrawFormatString(0, 16, 0xFFFFFF, "終了するにはescキーを押してください");
	DrawFormatString(0, 32, 0xFFFFFF, "X:%d Y:%d", pl->get_point(0), pl->get_point(1));
	pl->draw();

}

void GameScene::update_late() {
	pl->update_late();
}

float GameScene::get_time() { return time; }

int GameScene::get_xy(int num) {
	if (num == 0)return x;
	else         return y;
}