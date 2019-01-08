#include"shikimi_shotEfects.hpp"

shikimi_shotEfects::shikimi_shotEfects() {
	int x, y = 0;
	InitGraph("img/Efect/player/shikimi/shot/");
	anim_length = (unsigned)gra.size();
	anim_State = 0;
}

shikimi_shotEfects::~shikimi_shotEfects() {
	for (int i = 0, n = (unsigned)gra.size(); i < n; i++)DeleteGraph(gra[i]);
}

