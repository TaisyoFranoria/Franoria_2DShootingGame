#include"EfectBase.hpp"

EfectBase::EfectBase() {
	x, y, anim_State, anim_length = 0;
	alive = false;
}

EfectBase::~EfectBase() {
	for (int i = 0, n = (unsigned)gra.size(); i < n; i++)DeleteGraph(gra[i]);
}

void EfectBase::update() {
	
}

void EfectBase::draw() {
	if (alive)DrawRotaGraph(x,y,1.0,PI*2,gra[anim_State],TRUE);
}

void EfectBase::spawn(int x,int y) {
	this->x = x;
	this->y = y;
	alive = true;
}

void EfectBase::update_abs() {
	anim_State++;
	if (anim_State >= anim_length) { alive = false; anim_State = 0; }
}

void EfectBase::InitGraph(std::string filepath) {
	for (int i = 0; i < 20; i++) {
		std::string path = filepath + std::to_string(i) + ".png";
		int handle = LoadGraph(path.c_str());
		if (handle == -1)break;
		else gra.push_back(handle);
	}
	if (gra.size() == 0)DebugBreak();
}


