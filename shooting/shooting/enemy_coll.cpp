#include"enemy_shot.hpp"

enemy_shot::enemy_shot() {

}

enemy_shot::~enemy_shot() {

}

void enemy_shot::update() {

}

void enemy_shot::draw() {

}

void enemy_shot::enemy_coll(player* pl) {
	if (true) {
		int xtox = x - pl->get_point(2);
		int ytoy = y - pl->get_point(3);
		int rtor = r + (PLAYER_SIZE / 4);
		//if (xtox*xtox + ytoy * ytoy < rtor*rtor);
	}
}