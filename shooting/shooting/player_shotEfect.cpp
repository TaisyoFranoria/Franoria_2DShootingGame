#include"player_shotEfect.hpp"

player_shotefect::player_shotefect() {
	x, y, anim_State, anim_length = 0;
	alive = false;
}

player_shotefect::~player_shotefect() {

}

void player_shotefect::update() {
	if (alive)update_abs();
}