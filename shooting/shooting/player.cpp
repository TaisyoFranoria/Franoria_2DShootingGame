#include"player.hpp"

player::player() {
	initialize();
}

player::~player() {
	finalize();
}

void player::initialize() {
	x = 0;
	y = 0;
	for (int i = 0, n = (unsigned)(sizeof(gra) / sizeof(gra[0])); i < n; i++)gra[i] = InitLoadGraph(i);
	move_num = 2;
	anim_counter = 1;
}


void player::finalize() {
	for (int i = 0, n = (unsigned)(sizeof(gra) / sizeof(gra[0])); i < n; i++)DeleteGraph(gra[i]);
}

void player::update() {

	//テスト　あとでバリバリ変える
	

	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		x += 5;
		move_num = 3;
	}else if (CheckHitKey(KEY_INPUT_LEFT)) {
		x -= 5;
		move_num = 1;
	}
	else move_num = 2;

	if (CheckHitKey(KEY_INPUT_UP)) {
		y -= 5;
	}
	if (CheckHitKey(KEY_INPUT_DOWN)) {
		y += 5;
	}

	if (anim_counter > -5) anim_counter++;
	else if (anim_counter < 5)anim_counter--;

}

void player::draw() {
	DrawGraph(x, y, DrawPlayerGraph(move_num), TRUE);
}

void player::update_late() {

}

int player::get_point(int num) {
	switch (num) {
	case 0:
		return x;
	case 1:
		return y;
	default:
		return -1;
	//エラー
	}
}

int player::get_status(int num) {
	switch (num) {
	case 0:
		return status.LIFE;
	case 1:
		return status.BOMB;
	case 2:
		return status.COUNTINUE;
	default:
		return -1;
	//エラー　：－１
	}
}

int player::InitLoadGraph(int num) {
	switch (num) {
	case 0:
		return LoadGraph("img/player/Shikimi/5.png");
	case 1:
		return LoadGraph("img/player/Shikimi/4.png");
	case 2:
		return LoadGraph("img/player/Shikimi/6.png");
	default:
		return -1;
	}
}

int player::DrawPlayerGraph(int num) {
	switch (num) {
	case 1:
		return gra[1];
	case 2:
		return gra[0];
	case 3:
		return gra[2];
	default:
		return -1;
	}
}