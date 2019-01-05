#include"debug_zone.hpp"

debug_zone::debug_zone() {

}

debug_zone::~debug_zone() {

}

void debug_zone::update() {
	UI->updateUI(pl);
	pl->update();

	if (CheckHitKey(KEY_INPUT_1))pl->set_status(2, pl->get_status(2) + 1);
	if (CheckHitKey(KEY_INPUT_2))pl->set_status(0, pl->get_status(0) - 1);
	if (CheckHitKey(KEY_INPUT_ESCAPE))alive = false;
}