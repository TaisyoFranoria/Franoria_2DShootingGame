#include"UI.hpp"

UI_gamescene::UI_gamescene(player* pl) {
	initialize(pl);
}

UI_gamescene::~UI_gamescene() {
	finalize();
}

void UI_gamescene::initialize(player* pl) {
	pl_life =  pl->get_status(0);
	pl_lifeMAX = pl_life;
	pl_bomb = pl->get_status(1);
	pl_pow = pl->get_status(2);
	pl_powMAX = 100;

	init_graph();
}

void UI_gamescene::init_graph() {
	gra.push_back(LoadGraph("img/UI/Big_UI2.png"));
	gra.push_back(LoadGraph("img/UI/g_pw.png"));
	gra.push_back(LoadGraph("img/UI/g_life.png"));
}

void UI_gamescene::finalize() {
	for (int i = 0, n = (unsigned)gra.size(); i < n; i++)DeleteGraph(gra[i]);
}

void UI_gamescene::updateUI(player* pl) {
	update(pl);
	draw();
}

void UI_gamescene::update(player* pl) {
	DrawGraph(0,0,gra[0],TRUE);
	
	DrawExtendGraph(930,80,930+(200*((float)pl->get_status(0)/ (float)pl_lifeMAX)),98,gra[2],TRUE);
	DrawExtendGraph(930,100,930+(200*((float)pl->get_status(2)/ (float)pl_powMAX)),118,gra[1],TRUE);
	DrawFormatString(880,120,0xFFFFFF,"BOMB: %d",pl->get_status(1));
	DrawFormatString(880, 80, 0xFFFFFF, "LIFE:      %d", pl->get_status(0));
	DrawFormatString(880, 100, 0xFFFFFF, "POW :      %d", pl->get_status(2));
}

void UI_gamescene::draw() {

}

