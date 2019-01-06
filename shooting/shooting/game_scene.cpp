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
	bg = new BackGraph();
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

	//ƒQ[ƒ€ƒ][ƒ“‚©‚ço‚È‚¢‚½‚ß‚Ìˆ—
	if (pl->get_point(0) > GAME_WIDTH-64) pl->set_point(GAME_WIDTH-64, pl->get_point(1));
	if (pl->get_point(1) > GAME_HIGHT-64) pl->set_point(pl->get_point(0), GAME_HIGHT-64);
	if (pl->get_point(0) < 0)pl->set_point(0, pl->get_point(1));
	if (pl->get_point(1) < 0)pl->set_point(pl->get_point(0), 0);
}

float GameScene::get_time() { return time; }

int GameScene::get_xy(int num) {
	if (num == 0)return x;
	else         return y;
}