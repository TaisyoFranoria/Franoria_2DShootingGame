#include"Game.hpp"

Game::Game() {
	initialize();
}
Game::~Game() {
	finalize();
}

void Game::initialize() {
	alive = true;
	sc = new scene();
}

void Game::finalize() {
	delete sc;
}

void Game::update() {
	if (CheckHitKey(KEY_INPUT_ESCAPE))alive = false;
	sc->update();
}

void Game::draw() {
	sc->draw();
}

void Game::update_late() {
	sc->update_late();
}

void Game::all() {
	update();
	draw();
	update_late();
}