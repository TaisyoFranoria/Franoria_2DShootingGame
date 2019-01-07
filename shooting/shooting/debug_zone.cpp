#include"debug_zone.hpp"


debug_zone::debug_zone() {

}

debug_zone::~debug_zone() {

}

void debug_zone::update() {
	UI->updateUI(pl);
	bg->PlayGraph();
	update_abs();

	if (CheckHitKey(KEY_INPUT_1))pl->set_status(2, pl->get_status(2) + 1);
	if (CheckHitKey(KEY_INPUT_2))pl->set_status(0, pl->get_status(0) - 1);
	if (CheckHitKey(KEY_INPUT_3))pl_Bull[0]->shoot(800,700);
	if (CheckHitKey(KEY_INPUT_ESCAPE))alive = false;

	if (time % 100 == 0) { Item[Itemcount]->spawn(100,100); Itemcount++; }
	if (time % 150 == 0) { Item[Itemcount]->spawn(600, 100); Itemcount++; }
	if (time == 100)enm[0]->spawn(300,400);

}

void debug_zone::draw() {
	draw_abs();

	DrawFormatString(0, 0, 0xFFFFFF, "Running...");
	DrawFormatString(0, 16, 0xFFFFFF, "終了するにはescキーを押してください");
	DrawFormatString(0,32,0xFFFFFF,"X:%d Y:%d",pl->get_point(0),pl->get_point(1));
	if (pl_Bull[0]->alive)DrawFormatString(0, 48, 0xFFFFFF, "shoting");
	//DrawFormatString(0, 64, 0xFFFFFF, "bullet_count:%d",bullet_count);
	//DrawFormatString(0, 80, 0xFFFFFF, "bullet_length:%d", (unsigned)(sizeof(pl_Bull) / sizeof(pl_Bull[0])));
}