#include"Game.hpp"

Game::Game() {
	initialize();
}
Game::~Game() {
	finalize();
}

void Game::initialize() {
	alive = true;
	sc.push_back(new debug_zone());
	scene_num = 0;
}

void Game::finalize() {
	for (int i = 0, n = (unsigned)sc.size(); i < n;i++)delete sc[i];
}

void Game::update() {
	sc[scene_num]->update();
}

void Game::draw() {
	sc[scene_num]->draw();
}

void Game::update_late() {
	sc[scene_num]->update_late();
	
}

void Game::all() {
	if (!sc[scene_num]->get_alive()) { sc[scene_num] = NULL; scene_num++; }
	if (scene_num >= sc.size())alive = false;
	if (alive) {
		update();
		draw();
		update_late();
	}
}