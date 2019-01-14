#pragma once
#include"shot.hpp"

shot::shot() {
	x, y, gra,snd_coll = 0;
	alive = false;
}

shot::~shot() {
	DeleteGraph(gra);
}

void shot::shoot(int x,int y) {
	alive = true;
	this->x = x;
	this->y = y;
}

void shot::update() {

}

void shot::enemy_coll(EnemyBase* ene,EfectBase* efk) {
	if (ene->get_EnemyStatus(0)) {
		int xtox = x - ene->get_EnemyValue(0);
		int ytoy = y - ene->get_EnemyValue(1);
		int rtor = r + ene->get_EnemyValue(2);
		if (xtox*xtox + ytoy * ytoy < rtor*rtor)onColl(ene, efk);
	}
}

void shot::draw() {
	if(alive) DrawRotaGraph(x,y,1.5,PI*2,gra,TRUE);
}

void shot::onColl() {

}

void shot::onColl(EnemyBase* ene,EfectBase* efk) {
	ene->Damage(20);
	efk->spawn(x,y);
	PlaySoundMem(snd_coll,DX_PLAYTYPE_BACK);
	alive = false;
}