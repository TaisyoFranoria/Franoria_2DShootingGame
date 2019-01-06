#include"BackGraph.hpp"

BackGraph::BackGraph() {
	gra = LoadGraph("img/Back/2D/debugzone.png");
	x = 0;
	y = -1304;
	timecount = 0;
}

BackGraph::~BackGraph() {
	DeleteGraph(gra);
}

void BackGraph::update() {
	y++;
	if (y > 0)y = -1304;
}

void BackGraph::draw() {
	DrawGraph(x,y,gra,TRUE);
}

void BackGraph::PlayGraph() {
	update();
	draw();
}