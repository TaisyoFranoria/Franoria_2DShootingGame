#include"EnemyDestroyEFK.hpp"

EnemyDestroyEFK::EnemyDestroyEFK() {
	int x, y = 0;
	InitGraph("img/Efect/Enemy/destroy1/");
	anim_length = (unsigned)gra.size();
	anim_State = 0;
	edefk_count = 0;
}

EnemyDestroyEFK::~EnemyDestroyEFK() {
	for (int i = 0, n = (unsigned)gra.size(); i < n; i++)DeleteGraph(gra[i]);
}

void EnemyDestroyEFK::update() {
	if (alive) {
		edefk_count++;
		if(edefk_count%2==0)anim_State++;
		if (anim_State >= anim_length) { alive = false; anim_State = 0; }
	}
}

