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
	sc.push_back(new PoseScene());
	scene_num = 0;
	state = GAME_MAIN;
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
	switch (state) {
	case GAME_TITLE:
		break;
	case GAME_MAIN:
		if (!sc[scene_num]->get_alive()) { sc[scene_num] = NULL; scene_num++; }
		if (scene_num >= sc.size()-1)alive = false;
		if (alive) {
			update();
			draw();
			update_late();
		}
		if (sc[scene_num]->pose_now) {
			state = GAME_POSE;
			sc[scene_num]->pose_now = false;
		}
		break;
	case GAME_POSE:
		if (alive) {
			sc[sc.size() - 1]->update();
			sc[sc.size() - 1]->draw();
		}
		if (!sc[sc.size() - 1]->pose_now){
			state = GAME_MAIN; 
			sc[sc.size() - 1]->pose_now = true;
		}
		break;
	}
}