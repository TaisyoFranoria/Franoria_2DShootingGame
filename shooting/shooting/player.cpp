#include"player.hpp"

player::player() {
	initialize();
}

player::~player() {
	finalize();
}

void player::initialize() {
	x = 350;
	y = 600;
	hx = x + PLAYER_RADIUS;
	hy = y + PLAYER_RADIUS;

	for (int i = 0, n = (unsigned)(sizeof(gra) / sizeof(gra[0])); i < n; i++)gra[i] = InitLoadGraph(i);
	move_num = 2;
	anim_counter = 1;
	slow = false;

	status.LIFE = 100;
	status.BOMB = 2;
	status.POWER = 0;
	status.COUNTINUE = 0;
}


void player::finalize() {
	for (int i = 0, n = (unsigned)(sizeof(gra) / sizeof(gra[0])); i < n; i++)DeleteGraph(gra[i]);
}

void player::update() {

	//テスト　あとでバリバリ変える
	
	if (CheckHitKey(KEY_INPUT_LSHIFT)) slow = true;
	else slow = false;

	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		if (slow) x += 5;
		else x += 10;
		move_num = 3;
	}else if (CheckHitKey(KEY_INPUT_LEFT)) {
		if (slow) x -= 5;
		else x -= 10;
		move_num = 1;
	}
	else move_num = 2;

	if (CheckHitKey(KEY_INPUT_UP)) {
		if (slow) y -= 5;
		else y -= 10;
	}
	if (CheckHitKey(KEY_INPUT_DOWN)) {
		if (slow) y += 5;
		else y += 10;
	}

	if (anim_counter > -5) anim_counter++;
	else if (anim_counter < 5)anim_counter--;

	hx = x + (PLAYER_SIZE / 2);
	hy = y + (PLAYER_SIZE / 2);
}

void player::draw() {
	DrawExtendGraph(x, y,x+PLAYER_SIZE,y+PLAYER_SIZE, DrawPlayerGraph(move_num), TRUE);
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
		return status.POWER;
	case 3:
		return status.COUNTINUE;
	default:
		return -1;
	//エラー　：－１
	}
}

void player::set_status(int num, int value) {
	switch (num) {
	case 0:
		if (status.LIFE > 100)status.LIFE = 100;
		else status.LIFE = value;
		break;
	case 1:
		if (status.BOMB > 10)status.BOMB = 10;
		else status.BOMB = value;
		break;
	case 2:
		if (status.POWER >= 100) status.POWER = 100;
		else status.POWER = value;
		break;
	case 3:
		status.COUNTINUE = value;
		break;
	default:
		break;
	}
}

void player::set_point(int x, int y) {
	this->x = x;
	this->y = y;
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


