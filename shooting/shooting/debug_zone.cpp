#include"debug_zone.hpp"


debug_zone::debug_zone() {

}

debug_zone::~debug_zone() {

}

void debug_zone::update() {
	UI->updateUI(pl);
	bg->PlayGraph();
	update_abs();
	phase_frame++;

	switch (phase) {
	case 0:
		if (CheckHitKey(KEY_INPUT_1))pl->set_status(2, pl->get_status(2) + 1);
		if (CheckHitKey(KEY_INPUT_2))pl->set_status(0, pl->get_status(0) - 1);
		break;
	case 1:
		fadetitle();
		break;
	case 2:
		if (phase_frame % 100 == 0) { Item[Itemcount]->spawn(100, 100); Itemcount++; }
		if (phase_frame % 150 == 0) { Item[Itemcount]->spawn(600, 100); Itemcount++; }
		if (phase_frame == 100)enm[0]->spawn(300, 400);
		if (phase_frame == 200)enm[1]->spawn(400, 400);
		if (phase_frame == 300)enm[2]->spawn(500, 400);
		if (phase_frame == 310)enm[3]->spawn(400, 400);
		if (phase_frame == 320)enm[4]->spawn(430, 400);


		break;
	case 3:
		if (CheckHitKey(KEY_INPUT_1))pl->set_status(2, pl->get_status(2) + 1);
		if (CheckHitKey(KEY_INPUT_2))pl->set_status(0, pl->get_status(0) - 1);


		if (phase_frame % 100 == 0) { Item[Itemcount]->spawn(100, 100); Itemcount++; }
		if (phase_frame % 150 == 0) { Item[Itemcount]->spawn(600, 100); Itemcount++; }
		if (phase_frame == 100)enm[0]->spawn(300, 400);
		if (phase_frame == 200)enm[1]->spawn(400, 400);
		if (phase_frame == 300)enm[2]->spawn(500, 400);
		if (phase_frame == 310)enm[3]->spawn(400, 400);
		if (phase_frame == 320)enm[4]->spawn(430, 400);
		if (phase_frame == 400)for (int i = 5; i < 100; i++)enm[i]->spawn(400, 400);
		if (CheckHitKey(KEY_INPUT_4))enm[0]->respawn(400, 400);

		break;
	}



	if (CheckHitKey(KEY_INPUT_ESCAPE))alive = false;
	if (CheckHitKey(KEY_INPUT_0)) {phase = 0; phase_frame = 0;}
	if (CheckHitKey(KEY_INPUT_5)){phase = 1; phase_frame = 0;}
	if (CheckHitKey(KEY_INPUT_6)) { phase = 2; phase_frame = 0; }
	if (CheckHitKey(KEY_INPUT_7)) { phase = 3; phase_frame = 0; }
}

void debug_zone::draw() {
	draw_abs();
	if(phase==2)fadetitle();

	DrawFormatString(0, 0, 0xFFFFFF, "Running...");
	DrawFormatString(0, 16, 0xFFFFFF, "I—¹‚·‚é‚É‚ÍescƒL[‚ð‰Ÿ‚µ‚Ä‚­‚¾‚³‚¢");
	DrawFormatString(0,32,0xFFFFFF,"X:%d Y:%d",pl->get_point(0),pl->get_point(1));
	//DrawFormatString(0, 64, 0xFFFFFF, "destroy:%d",enm[0]->destroy_cnt);
	//DrawFormatString(0, 80, 0xFFFFFF, "bullet_length:%d", (unsigned)(sizeof(pl_Bull) / sizeof(pl_Bull[0])));
}