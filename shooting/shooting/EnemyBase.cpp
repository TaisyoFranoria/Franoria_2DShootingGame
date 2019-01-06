#include"EnemyBase.hpp"

EnemyBase::EnemyBase() {
	x, y, gra, anim_length ,hp,atk= 0;
	alive, shot = false;
}

EnemyBase::~EnemyBase() {
	for (int i = 0, n = (unsigned)gra.size(); i < n; i++)DeleteGraph(gra[i]);
}

int EnemyBase::get_EnemyValue(int num) {
	switch (num) {
	case 0 :
		return x;
	case 1:
		return y;
	default :
		return -1;
	}
}

bool EnemyBase::get_EnemyStatus(int num) {
	switch (num) {
	case 0:
		return alive;
	case 1:
		return shot;
	default:
		return false;
	}
}

void EnemyBase::Damage(int value) {
	hp -= value;
	if (hp <= 0)alive = false;
}

void EnemyBase::InitGraph(std::string filepath) {
	for (int i = 0; i < 20; i++) {
		std::string path = filepath + std::to_string(i) + ".png";
		int handle = LoadGraph(path.c_str());
		if (handle == -1)break;
		else gra.push_back(handle);
	}
}