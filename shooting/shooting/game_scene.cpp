#include"game_scene.hpp"

GameScene::GameScene() {
	initialize();
}

GameScene::~GameScene() {
	finalize();
}

void GameScene::initialize() {
	time = 0;
	//Ç†Ç∆Ç≈ïœçX
	x = 0;
	y = 0;

	pl = new player();
	for (int i = 0, n = (unsigned)(sizeof(pl_Bull) / sizeof(pl_Bull[0])); i < n; i++)pl_Bull[i] = new shikimi_shot();
	for (int i = 0, n = (unsigned)(sizeof(Item) / sizeof(Item[0])); i < n; i++)Item[i] = new atkup();
	bullet_count = 0;
	UI = new UI_gamescene(pl);
	bg = new BackGraph();
}

void GameScene::finalize() {
	delete pl;
	for (int i = 0, n = (unsigned)(sizeof(pl_Bull) / sizeof(pl_Bull[0])); i < n; i++)delete pl_Bull[i];
	for (int i = 0, n = (unsigned)(sizeof(Item) / sizeof(Item[0])); i < n; i++)delete Item[i];
	delete UI;
	delete bg;
}

void GameScene::update() {
	update_abs();
}

void GameScene::update_abs() {
	pl->update();
	if (time%3==0&&pl->get_now(1))shot_emit(pl->get_point(0), pl->get_point(1), pl->get_status(2), pl->get_now(0));
	for (int i = 0, n = (unsigned)(sizeof(Item) / sizeof(Item[0])); i < n; i++)Item[i]->update(pl);
	for (int i = 0, n = (unsigned)(sizeof(pl_Bull) / sizeof(pl_Bull[0])); i < n; i++) pl_Bull[i]->update();
}

void GameScene::draw() {
	draw_abs();
}

void GameScene::draw_abs() {
	for (int i = 0, n = (unsigned)(sizeof(Item) / sizeof(Item[0])); i < n; i++)Item[i]->draw();
	pl->draw();
	for (int i = 0, n = (unsigned)(sizeof(pl_Bull) / sizeof(pl_Bull[0])); i < n; i++) pl_Bull[i]->draw();
	
}

void GameScene::update_late() {
	pl->update_late();
	if (pl->get_status(0) <= 0) alive = false;

	//ÉQÅ[ÉÄÉ]Å[ÉìÇ©ÇÁèoÇ»Ç¢ÇΩÇﬂÇÃèàóù
	if (pl->get_point(0) > GAME_WIDTH-64) pl->set_point(GAME_WIDTH-64, pl->get_point(1));
	if (pl->get_point(1) > GAME_HIGHT-64) pl->set_point(pl->get_point(0), GAME_HIGHT-64);
	if (pl->get_point(0) < 0)pl->set_point(0, pl->get_point(1));
	if (pl->get_point(1) < 0)pl->set_point(pl->get_point(0), 0);

	if (bullet_count >= (unsigned)(sizeof(pl_Bull) / sizeof(pl_Bull[0])))bullet_count = 0;
	if (Itemcount >= (unsigned)(sizeof(Item) / sizeof(Item[0])))Itemcount = 0;
	update_ALT();
}

void GameScene::shot_emit(int x, int y,int pw,bool slow) {
	if (pw >= 100) {
		if (slow) { pl_Bull[bullet_count]->shoot(x + 40, y); bullet_count++; }
		else pl_Bull[bullet_count]->shoot(x+40, y); bullet_count++;
	}
	else if (pw >= 80) {
		if (slow) {}
		else pl_Bull[bullet_count]->shoot(x+40, y); bullet_count++;
	}
	else if (pw >= 60) {
		if (slow) {}
		else pl_Bull[bullet_count]->shoot(x +40, y); bullet_count++;
	}
	else if (pw >= 30) {
		if (slow) {}
		else pl_Bull[bullet_count]->shoot(x+40, y); bullet_count++;
	}
	else {
		pl_Bull[bullet_count]->shoot(x+40,y); bullet_count++;
	}
}

int GameScene::get_time() { return time; }

int GameScene::get_xy(int num) {
	if (num == 0)return x;
	else         return y;
}