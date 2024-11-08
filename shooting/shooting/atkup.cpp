#include"atkup.hpp"

atkup::atkup() {
	x = 0;
	y = 0;
	alive = false;
	pl_up = false;
	gra = LoadGraph("img/Item/atkup.png");
	snd = LoadSoundMem("snd/ki.ogg");
}

atkup::~atkup() {
	DeleteGraph(gra);
}

void atkup::onColl(player* pl) {
	pl->set_status(2, pl->get_status(2) + 2);
	alive = false;
	pl_up = false;
	PlaySoundMem(snd, DX_PLAYTYPE_BACK);
}