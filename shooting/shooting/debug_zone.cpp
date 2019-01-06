#include"debug_zone.hpp"

debug_zone::debug_zone() {

}

debug_zone::~debug_zone() {

}

void debug_zone::update() {
	UI->updateUI(pl);
	bg->PlayGraph();
	pl->update();

	if (CheckHitKey(KEY_INPUT_1))pl->set_status(2, pl->get_status(2) + 1);
	if (CheckHitKey(KEY_INPUT_2))pl->set_status(0, pl->get_status(0) - 1);
	if (CheckHitKey(KEY_INPUT_ESCAPE))alive = false;
}

void debug_zone::draw() {
	pl->draw();
	DrawFormatString(0, 0, 0xFFFFFF, "Running...");
	DrawFormatString(0, 16, 0xFFFFFF, "I—¹‚·‚é‚É‚ÍescƒL[‚ð‰Ÿ‚µ‚Ä‚­‚¾‚³‚¢");
	DrawFormatString(0,32,0xFFFFFF,"X:%d Y:%d",pl->get_point(0),pl->get_point(1));
}