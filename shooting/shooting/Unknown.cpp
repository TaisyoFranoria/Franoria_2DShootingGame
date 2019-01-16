#include"Unknown.hpp"

Unknown_::Unknown_() {
	x = 0;
	y = 0;
	InitGraph("img/Enemy/Unknown/");
	anim_length = (unsigned)gra.size();
	animState = 0;
	alive = false;
	shot = false;
	move_lange = GetRand(100);
	pt = GetRand(8);
	hp = 500;
	atk = 0;
	r = 32;
	sound_handle = LoadSoundMem("snd/expl.ogg");
	count = 0;
}

Unknown_::Unknown_(int x,int y,int hp,int atk) {
	this->x = x;
	this->y = y;
	InitGraph("img/Enemy/Unknown/");
	anim_length = (unsigned)gra.size();
	animState = 0;
	alive = false;
	shot = false;
	move_lange = GetRand(100);
	pt = GetRand(8);
	hp = 500;
	atk = 0;
	r = 32;
	sound_handle = LoadSoundMem("snd/expl.ogg");
	count = 0;
}

Unknown_::~Unknown_() {
	for (int i = 0, n = (unsigned)gra.size(); i < n; i++)DeleteGraph(gra[i]);
}

void Unknown_::update() {
	if (alive) {
		switch (pt) {
		case 0:
			y += 2;
			if (y > move_lange / 2) {
				pt = GetRand(8);
				move_lange = GetRand(100);
			}
			break;
		case 1:
			x += 2;
			if (x > move_lange / 2) {
				pt = GetRand(8);
				move_lange = GetRand(100);
			}
			break;
		case 2:
			y -= 2;
			if (y <-( move_lange / 2)) {
				pt = GetRand(8);
				move_lange = GetRand(100);
			}
			break;
		case 3:
			y += 2;
			if (x < -(move_lange / 2)) {
				pt = GetRand(8);
				move_lange = GetRand(100);
			}
			break;
		case 4:
			y++;
			x++;
			if (y > move_lange/4) {
				pt = GetRand(8);
				move_lange = GetRand(100);
			}
			break;
		case 5:
			y++;
			x--;
			if (y > move_lange / 4) {
				pt = GetRand(8);
				move_lange = GetRand(100);
			}
			break;
		case 6:
			y--;
			x++;
			if (x > move_lange / 4) {
				pt = GetRand(8);
				move_lange = GetRand(100);
			}
			break;
		case 7:
			y--;
			x--;
			if (y < -(move_lange / 4)) {
				pt = GetRand(8);
				move_lange = GetRand(100);
			}
			break;
		default :
			y--;
			x--;
			if (y < -(move_lange / 4)) {
				pt = GetRand(8);
				move_lange = GetRand(100);
			}
			break;
		}
		if (y > 900)alive = false;
		if (x > 900)alive = false;
		if (y < -15)alive = false;
		if (x < -15)alive = false;

		if (count % 6 == 0)animState++;
		if (animState >= anim_length)animState = 0;

		if (hp <= 0)destroy();
		count++;
	}

}

void Unknown_::update(EfectBase* efk) {
	if(alive) {
		switch (pt) {
		case 0:
			y += 2;
			if (y > move_lange / 2) {
				pt = GetRand(8);
				move_lange = GetRand(100);
			}
			break;
		case 1:
			x += 2;
			if (x > move_lange / 2) {
				pt = GetRand(8);
				move_lange = GetRand(100);
			}
			break;
		case 2:
			y -= 2;
			if (y < -(move_lange / 2)) {
				pt = GetRand(8);
				move_lange = GetRand(100);
			}
			break;
		case 3:
			y += 2;
			if (x < -(move_lange / 2)) {
				pt = GetRand(8);
				move_lange = GetRand(100);
			}
			break;
		case 4:
			y++;
			x++;
			if (y > move_lange / 4) {
				pt = GetRand(8);
				move_lange = GetRand(100);
			}
			break;
		case 5:
			y++;
			x--;
			if (y > move_lange / 4) {
				pt = GetRand(8);
				move_lange = GetRand(100);
			}
			break;
		case 6:
			y--;
			x++;
			if (x > move_lange / 4) {
				pt = GetRand(8);
				move_lange = GetRand(100);
			}
			break;
		case 7:
			y--;
			x--;
			if (y < -(move_lange / 4)) {
				pt = GetRand(8);
				move_lange = GetRand(100);
			}
			break;
		default:
			y--;
			x--;
			if (y < -(move_lange / 4)) {
				pt = GetRand(8);
				move_lange = GetRand(100);
			}
			break;
		}
		if (y > 900)alive = false;
		if (x > 900)alive = false;
		if (y < -15)alive = false;
		if (x < -15)alive = false;

		if (count % 6 == 0)animState++;
		if (animState >= anim_length)animState = 0;

		if (hp <= 0)destroy(efk);
		count++;
	}
}

void Unknown_::draw() {
	if (alive) {
		DrawRotaGraph(x,y,1.0,PI*2,gra[animState],TRUE);
	}
}

void Unknown_::spawn(int x, int y) {
	this->x = x;
	this->y = y;
	alive = true;
}

void Unknown_::respawn(int x,int y) {
	this->x = x;
	this->y = y;
	alive = true;
	hp = 9999;
}

